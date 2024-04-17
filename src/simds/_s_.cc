#include "../../include/_simd_.hpp"
#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#if __OS_VER__ != 2

#include <immintrin.h>
 
#include <cstdlib>

void TestLA()
{

}

void Testvec256()
{
    auto m256_fixed = 8;
    auto _src0 = static_cast<float *>(malloc(sizeof(float) * m256_fixed));
    memset(_src0, 0x0, m256_fixed * sizeof(float));
    auto _src1 = static_cast<float *>(malloc(sizeof(float) * m256_fixed));
    memset(_src1, 0x0, m256_fixed * sizeof(float));
    auto _dest = static_cast<float *>(malloc(sizeof(float) * m256_fixed));

    _mm256_storeu_ps(_dest, _mm256_add_ps(_mm256_loadu_ps(_src0), _mm256_loadu_ps(_src1)));

    Alan::ConsoleBeautyOutput(_dest, m256_fixed);

    free(_dest);
    free(_src1);
    free(_src0);
}

#endif