#include <immintrin.h>
#include <stdio.h>

int main() {
   /*
   Incializa um vetor com função intrinseca AVX
   Funções AVX inicializam vetores de 256 bits
   As funções AVX são escritas utilizando _mm256_
   */
  
    __m256d vetorAVX = _mm256_setr_pd(1.0, 2.0, 4.0, 8.0);
    __m256d vetorAVXNegativos = _mm256_setr_pd(-2.0, -2.0, -4.0, -4.0);
    
    // soma os vetores de 256 bits que contém double
    __m256d resultadoAVX = _mm256_add_pd(vetorAVX, vetorAVXNegativos);
    double* f2 = (double*)&resultadoAVX;
    printf("AVX \n%f, %f, %f, %f", f2[0], f2[1], f2[2], f2[3]);

}