#include "real.h"

__constant uint MOD = (1 << 17) - 1;

// https://stackoverflow.com/questions/9912143/how-to-get-a-random-number-in-opencl
inline uint xor_shift(uint2 randoms, size_t globalID){
    // 'randoms' is uint2 passed to kernel
    uint seed = randoms.x + globalID;
    uint t = seed ^ (seed << 11);
    uint result = randoms.y ^ (randoms.y >> 19) ^ (t ^ (t >> 8));
    return result;
}

inline real gen_random(const real x){
    const real base = (real) 65536.0;
    const real a = (real) 3289579.0;
    const real b = (real) 90238493.0;
    __private const real t = fma(a, x, b) / base;
    return fmod(t, (real) 1.0);
}

inline real gen_random_with_max(const real x, const real m){
    return gen_random(x) * m;
}

inline real3 gen_randoms3_with_max_normal2(const real x, const real max_normal2){
    __private const real max_normal = sqrt(max_normal2);
    __private real r = sqrt(gen_random_with_max(x, max_normal2)),
                    t = r / max_normal;
    t = gen_random(t);
    __private real theta = M_PI * t;
    t = gen_random(t);
    __private real phi = 2 * M_PI * t;
    return (real3) (r * sin(theta) * cos(phi), r * sin(theta) * sin(phi), r * cos(theta));
}

// |v|^2 should be in [0, max_normal2]
__kernel void gen_randoms3s_with_max_normal2(__global real3* const v, const real max_normal2, const uint2 seed){
    const size_t i = get_global_id(0);
    const size_t n = get_global_size(0);
    __private real t = ((real) xor_shift(seed, i)) / MOD;
    v[i] = gen_randoms3_with_max_normal2(t, max_normal2);
}

__kernel void gen_randoms3s_with_boundary(__global real3* const v, const real3 boundary, const uint2 seed){
    const size_t i = get_global_id(0);
    const size_t n = get_global_size(0);
    __private real t = ((real) xor_shift(seed, i)) / MOD;
    __private real3 t3 = gen_randoms3_with_max_normal2(t, 1.0);
    v[i] = boundary * t3;
}
