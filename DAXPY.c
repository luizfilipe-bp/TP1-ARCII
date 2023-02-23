#include <immintrin.h>
#include <stdio.h>
#include <stdalign.h>

int main() {
    //Cria os vetor que serão carregados e faz o alinhamento de bits
    alignas(32) float vetorMemoria1[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0 ,7.0 ,8.0};
    __m256 vetorX = _mm256_load_ps(vetorMemoria1);
    alignas(32) float vetorMemoria2[8] = {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0};
    __m256 vetorY = _mm256_load_ps(vetorMemoria2);

    //Pede o valor do escalar via cmd
    int escalar;
    printf("Digite o valor do escalaaar: ");
    scanf("%d", &escalar);
    //Set um vetor que possui todos valores o valor do escalar
    __m256 vetorEscalar = _mm256_set1_ps(escalar);
    
    //Multiplica o vetorX com o vetor escalar e soma com o vetor y
    __m256 resultadoDAXPY = _mm256_fmadd_ps(vetorX, vetorEscalar, vetorY);
    alignas(32) float vetorResultado[8];
    _mm256_store_ps(vetorResultado, resultadoDAXPY);
    printf("Resultado DAXPY \n%f, %f, %f, %f, %f, %f, %f, %f", vetorResultado[0], vetorResultado[1], vetorResultado[2], vetorResultado[3], vetorResultado[4], vetorResultado[5], vetorResultado[6], vetorResultado[7]);
}