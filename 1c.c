#include <immintrin.h>
#include <stdio.h>

int main() {
    /*
    Inicializa um vetor com função intrinseca SSE
    Funções SSE inicializam vetores de 128 bits
    As funções SSE são escritas utilizando _mm_
    */
   __m128 vetor4Floats = _mm_setr_ps(1.0, 2.0, 3.0, 4.0);
   __m128 vetor4FloatsPrimos = _mm_setr_ps(2.0, 3.0 ,5.0, 7.0);
   
   //soma os vetores de 128 bits
   __m128 resultadoSSE = _mm_add_ps(vetor4Floats, vetor4FloatsPrimos);
   float* f = (float*)&resultadoSSE;
   printf("SSE \n%f, %f, %f, %f\n\n", f[0], f[1], f[2], f[3]);

   /*
   Incializa um vetor com função intrinseca AVX
   Funções AVX inicializam vetores de 256 bits
   As funções AVX são escritas utilizando _mm256_
   */
  
    __m256 vetorAVX = _mm256_setr_ps(1.0, 2.0, 3.0, 4.0, 5.0, 6.0 ,7.0 ,8.0);
    __m256 vetorAVXDobro = _mm256_setr_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
    
    // soma os vetores de 256 bits
    __m256 resultadoAVX = _mm256_add_ps(vetorAVX, vetorAVXDobro);
    float* f2 = (float*)&resultadoAVX;
    printf("AVX \n%f, %f, %f, %f, %f, %f, %f, %f", f2[0], f2[1], f2[2], f2[3], f2[4], f2[5], f2[6], f2[7]);

}