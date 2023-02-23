#include <immintrin.h>
#include <stdio.h>

int main() {
    int opcao;
    do{
        printf("Selecione a opcao de tipo de dados do vetor\n");
        printf("1- double (4 x 64bits)\n");
        printf("2- float (8 x 32bits)\n");
        printf("3- integer (8 x 32 bits)\n");
        scanf("%d", &opcao);
    }while(!((opcao>= 1) && (opcao <=3)));

    if(opcao == 1){
        double vEntrada[4];
        printf("Digite 4 valores para o primeiro vetor: ");
        scanf("%lf %lf %lf %lf", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3]);
        __m256d a = _mm256_setr_pd(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3]);

        printf("Digite 4 valores para o segundo vetor: ");
        scanf("%lf %lf %lf %lf", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3]);
        __m256d b = _mm256_setr_pd(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3]);

        printf("Digite 4 valores para o terceiro vetor: ");
        scanf("%lf %lf %lf %lf", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3]);
        __m256d c = _mm256_setr_pd(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3]);

        __m256d resultado = _mm256_fmaddsub_pd(a, b, c);

        double* resultadoFMA = (double*)&resultado; 
        printf("Resultado\n");
        for(int i = 0; i < 4; i++){
            printf("%lf  ", resultadoFMA[i]);
        }
    }else if(opcao == 2){
        float vEntrada[8];
        printf("Digite 8 valores para o primeiro vetor: ");
        scanf("%f %f %f %f %f %f %f %f", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3], &vEntrada[4],&vEntrada[5],&vEntrada[6],&vEntrada[7]);
        __m256 a = _mm256_setr_ps(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3], vEntrada[4], vEntrada[5], vEntrada[6], vEntrada[7]);

        printf("Digite 8 valores para o segundo vetor: ");
        scanf("%f %f %f %f %f %f %f %f", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3], &vEntrada[4],&vEntrada[5],&vEntrada[6],&vEntrada[7]);
        __m256 b = _mm256_setr_ps(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3], vEntrada[4], vEntrada[5], vEntrada[6], vEntrada[7]);

        printf("Digite 8 valores para o terceiro vetor: ");
        scanf("%f %f %f %f %f %f %f %f", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3], &vEntrada[4],&vEntrada[5],&vEntrada[6],&vEntrada[7]);
        __m256 c = _mm256_setr_ps(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3], vEntrada[4], vEntrada[5], vEntrada[6], vEntrada[7]);

        __m256 resultado = _mm256_fmaddsub_ps(a, b, c);

        float* resultadoFMA = (float*)&resultado; 
        printf("Resultado\n");
        for(int i = 0; i < 8; i++){
            printf("%f  ", resultadoFMA[i]);
        }

    }else if(opcao == 3) {
        int vEntrada[8];
        printf("Digite 8 valores para o primeiro vetor: ");
        scanf("%d %d %d %d %d %d %d %d", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3], &vEntrada[4],&vEntrada[5],&vEntrada[6],&vEntrada[7]);
        __m256i a = _mm256_setr_epi32(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3], vEntrada[4], vEntrada[5], vEntrada[6], vEntrada[7]);

        printf("Digite 8 valores para o segundo vetor: ");
        scanf("%d %d %d %d %d %d %d %d", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3], &vEntrada[4],&vEntrada[5],&vEntrada[6],&vEntrada[7]);
        __m256i b = _mm256_setr_epi32(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3], vEntrada[4], vEntrada[5], vEntrada[6], vEntrada[7]);

        printf("Digite 8 valores para o terceiro vetor: ");
        scanf("%d %d %d %d %d %d %d %d", &vEntrada[0],&vEntrada[1],&vEntrada[2],&vEntrada[3], &vEntrada[4],&vEntrada[5],&vEntrada[6],&vEntrada[7]);
        __m256i c = _mm256_setr_epi32(vEntrada[0],vEntrada[1],vEntrada[2],vEntrada[3], vEntrada[4], vEntrada[5], vEntrada[6], vEntrada[7]);
       
        //multiplica ab
        __m256i AB = _mm256_mullo_epi32(a, b); 
        //subtrai c
        __m256i ABSubC = _mm256_sub_epi32(AB, c);
        //soma c
        __m256i ABAddC = _mm256_add_epi32(AB, c);

        int resultadoFMA[8];
        //armazena os valores de acordo com a mascara
        __m256i mask = _mm256_setr_epi32(-10, 1, -10, 1, -10, 1, -10, 1);
        _mm256_maskstore_epi32(resultadoFMA, mask, ABSubC);

        //armazena os valores de acordo com a mascara
        mask = _mm256_setr_epi32(1, -10, 1, -10, 1, -10, 1, -10);
        _mm256_maskstore_epi32(resultadoFMA, mask, ABAddC);
        
        printf("Resultado\n");
        for(int i = 0; i < 8; i++){
            printf("%d  ", resultadoFMA[i]);
        }
    }
    
}