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

/*
__kernel void cal(__global real m, __global real3* r, __global real3* v, __global real3* a, const real dt){

}
*/



