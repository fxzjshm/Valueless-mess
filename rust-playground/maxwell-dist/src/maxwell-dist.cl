#ifndef DOUBLEPREC
    #ifdef cl_khr_fp64
        #define DOUBLEPREC 1
    #else
        #define DOUBLEPREC 0
    #endif // cl_khr_fp64
#endif // DOUBLEPREC

#if DOUBLEPREC
typedef double real;
typedef double2 real2;
typedef double3 real3;
typedef double4 real4;
#else
typedef float real;
typedef float2 real2;
typedef float3 real3;
typedef float4 real4;
#endif /* DOUBLEPREC */

inline real3 get_acceleration(real m, real3 g){
    return m * g;
}

// collision with the wall
inline void check_boundary(real3* r, real3* v, const real3 boundary[2]){
    #pragma unroll
    for (unsigned int i = 0; i < 4; i++){
        // assuming boundary[0] is always 0
        if ((*r)[i] < boundary[0][i]){
            (*r)[i] = 2 * boundary[0][i] - (*r)[i];
            (*v)[i] = -(*v)[i];
        }
        if ((*r)[i] > boundary[1][i]){
            (*r)[i] = 2 * boundary[1][i] - (*r)[i];
            (*v)[i] = -(*v)[i];
        }
    }
}

__kernel void update(__global real3* r, __global real3* v, __global real3* a,
                    __global real* m, const real3 g, const real3 boundary, const real dt){
    __private unsigned int i = get_global_id(0);
    __private real m_i = m[i];
    __private real3 r_i = r[i],
                    v_i = v[i],
                    a_i = get_acceleration(m_i, g);
    r_i += (v_i * dt) + (a_i * (dt / 2.0));
    v_i += a_i * dt;

    const real3 boundary0 = (real3)(0.0, 0.0, 0.0);
    check_boundary(&r_i, &v_i, (real3[2]){boundary0, boundary});
}
