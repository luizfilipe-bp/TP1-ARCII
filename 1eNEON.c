#include <stdio.h>
#include <arm_neon.h>

int main()
{
     //inicialização de vetores utilizando funções intrinsecas ARM NEON
     float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
     float32x4_t v2 = { 1.0, 2.0, 3.0, 4.0 };
     //Soma de dois vetores que possuem 4 floats de 32 bits cada
     float32x4_t sum = vaddq_f32(v1, v2);
}