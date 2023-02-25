#include <immintrin.h>
#include <stdio.h>

int main() {
    //Utilizando elementos de 8 bits o valor minimo armazenado é de -128 e o máximo é 127
    //Com uma função que não utiliza saturação os valores resultantes não irão respeitar os limites
    __m256i a = _mm256_setr_epi8(0, 10, 20, 30, 40, 50, 60, 127, 0, 127, 0, 127, 159, 248, 61, 127,
                                 41, 10, 114, 89, 237, 18, 223, 147, 98, 135, 56, 202, 11, 172, 201, 30);
    printf("Valores do vetor A\n");
    char* veC = (char*)&a;
    for(int i = 0; i < 32; i++){
        printf("%d ", veC[i]);
    }
    printf("\n");
    __m256i b = _mm256_setr_epi8(0, 10, 20, 30, 40, 50, 60, 0, 127, 1, 127, 2, 139, 246, 84, 57,
                                 187, 99, 55, 156, 183, 38, 163, 221, 24, 92, 129, 79, 237, 222, 17, 147);
    printf("\nValores do vetor B\n");
    char* vetorB = (char*)&b;
    for(int i = 0; i < 32; i++){
        printf("%d ", vetorB[i]);
    }
    printf("\n");
    __m256i somaSemSaturacao = _mm256_add_epi8(a, b);
    printf("\nUtilizacao do _mm256_add_epi8 \nValores do vetor resultante da soma do vetor A com B\n");
    char* resultadoSemSaturacao = (char*)&somaSemSaturacao;
    for(int i = 0; i < 32; i++){
        printf("%d ", resultadoSemSaturacao[i]);
    }

    
    //Utilizando elementos de 16 bits o valor minimo armazenado é de -32768 e o máximo é 32767
    //Com uma função que utiliza saturação os valores armazenados estarão dentro dos limites
    __m256i c = _mm256_setr_epi16(-31768, -31768, -31768, -31768, -31768, -31768, -31768, -31768, -31768, -31768,
                                  -31768, -31768, -31768, -31768, -31768, 2000);
    printf("\n\n\nValores do vetor C\n");
    short* vetorC = (short*)&c;
    for(int i = 0; i < 16; i++){
        printf("%d ", vetorC[i]);
    }
    printf("\n");
    __m256i d = _mm256_setr_epi16(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1001, 1002, 1003, 4000, 10000, -31767);
    printf("\nValores do vetor D\n");
    short* vetorD = (short*)&d;
    for(int i = 0; i < 16; i++){
        printf("%d ", vetorD[i]);
    }
    printf("\n");
    __m256i subComSaturacao = _mm256_subs_epi16(c, d);
    printf("\nUtilizacao do _mm256_subs_epi16 \nValores do vetor resultante da soma do vetor C com D\n");
    short* resultadoComSaturacao = (short*)&subComSaturacao;
    for(int i = 0; i < 16; i++){
        printf("%d ", resultadoComSaturacao[i]);
    }
}