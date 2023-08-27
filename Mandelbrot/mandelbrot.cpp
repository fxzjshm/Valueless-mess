/******************************************************************************* 
 * Copyright (c) 2023 fxzjshm
 * This file is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 ******************************************************************************/

#if __has_include(<sycl/sycl.hpp>)
#define MANDELBROT_HAS_SYCL
#endif

#ifdef MANDELBROT_HAS_SYCL
#include <sycl/sycl.hpp>
#endif

#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_complex.hpp>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <type_traits>

namespace mandelbrot {

#define MANDELBROT_FORWARD(func)                    \
  template <typename T>                             \
  auto func(T x) {                                  \
    if constexpr (std::is_same<T, float>::value ||  \
                  std::is_same<T, double>::value) { \
      return std::func(x);                          \
    } else {                                        \
      return boost::multiprecision::func(x);        \
    }                                               \
  }

MANDELBROT_FORWARD(abs);
MANDELBROT_FORWARD(log);
MANDELBROT_FORWARD(log2);

template <typename T, typename C>
auto mandelbrot(C c, uint64_t max_iter) -> T {
  C z = 0;
  uint64_t n = 0;
  while (abs(z) <= 2 && n < max_iter) {
    z = z * z + c;
    n += 1;
  }
  if (n == max_iter) {
    return max_iter;
  }
  return n + 1 - log(log2(abs(z)));
}

template <typename T, typename C>
auto mandelbrot_set(size_t width, size_t height, T x_min, T x_max, T y_min,
                    T y_max, uint64_t max_iter) {
  const size_t total_count = width * height;
  std::vector<T> mandelbrot_output;
  mandelbrot_output.resize(total_count);
  const T dx = (x_max - x_min) / (width - 1);
  const T dy = (y_max - y_min) / (height - 1);

#ifndef MANDELBROT_HAS_SYCL
#pragma omp parallel
  for (size_t i = 0; i < height; i++) {
#pragma omp simd
    for (size_t j = 0; j < width; j++) {
      T x = x_min + j * dx;
      T y = y_min + i * dy;
      mandelbrot_output[i * width + j] = mandelbrot<T, C>(C{x, y}, max_iter);
    }
  }
#else
  sycl::queue q;
  std::cout << "Queue Device: "
            << q.get_device().get_info<sycl::info::device::name>() << std::endl;
  std::cout << "Queue Device Vendor: "
            << q.get_device().get_info<sycl::info::device::vendor>()
            << std::endl;
  T* d_out = sycl::malloc_device<T>(total_count, q);

  q.parallel_for(sycl::range<2>{width, height}, [=](sycl::item<2> id) {
     const auto j = id.get_id(0), i = id.get_id(1);
     T x = x_min + j * dx;
     T y = y_min + i * dy;
     d_out[i * width + j] = mandelbrot<T, C>(C{x, y}, max_iter);
   }).wait();
  q.copy(d_out, &mandelbrot_output[0], total_count).wait();
#endif  // !MANDELBROT_HAS_SYCL

  return mandelbrot_output;
}

}  // namespace mandelbrot

int main() {
  using real = double;  //boost::multiprecision::cpp_bin_float_oct;
  using complex = std::complex<real>;  //boost::multiprecision::cpp_complex_oct;

  size_t width = 3840, height = 2160;
  real x_min = -2.0, x_max = 1.0;
  real y_min = -1.5, y_max = 1.5;
  uint64_t max_iter = 100;

  auto mandelbrot_output = mandelbrot::mandelbrot_set<real, complex>(
      width, height, x_min, x_max, y_min, y_max, max_iter);

  {
    std::ofstream fout{"mandelbrot_output.txt"};
    for (size_t i = 0; i < height; i++) {
      fout << static_cast<double>(mandelbrot_output[i * width]);
      for (size_t j = 1; j < width; j++) {
        fout << " " << static_cast<double>(mandelbrot_output[i * width + j]);
      }
      fout << "\n";
    }
    fout.flush();
  }

  return 0;
}
