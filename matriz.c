#include <immintrin.h>
#include <stdio.h>
#include <stdalign.h>

int main() {
    int linhaMatriz1 = 1;
    int colunaMatriz1 = 1;
    do{
        printf("Digite a quantidade de linhas e colunas da primeira matriz: ");
        scanf("%d %d", &linhaMatriz1, &colunaMatriz1);
        if(!(linhaMatriz1 >= 1 && linhaMatriz1 <=4) && !(colunaMatriz1 >= 1 && colunaMatriz1 <=4)){
            printf("O valor minimo para uma linha ou coluna e de 1 e o valor maximo e de 4\n");
        }
    }while(!(linhaMatriz1 >= 1 && linhaMatriz1 <=4) && !(colunaMatriz1 >= 1 && colunaMatriz1 <=4));
    
    int linhaMatriz2 = 1;
    int colunaMatriz2 = 1;
    do{
        printf("Digite a quantidade de linhas e colunas da segunda matriz: ");
        scanf("%d %d", &linhaMatriz2, &colunaMatriz2);
        if(!(linhaMatriz2 >= 1 && linhaMatriz2 <=4) && !(colunaMatriz2 >= 1 && colunaMatriz2 <=4)){
            printf("O valor minimo para uma linha ou coluna e de 1 e o valor maximo e de 4\n");
        }
    }while(!(linhaMatriz2 >= 1 && linhaMatriz2 <=4) && !(colunaMatriz2 >= 1 && colunaMatriz2 <=4));

    if((linhaMatriz1 == linhaMatriz2) && (colunaMatriz1 == colunaMatriz2)){
        //vetor de quatro posições, quantidade máxima de colunas da matriz,
        //para receber os valores de entrada das colunas da matriz
        double matriz1[4] = {0,0,0,0};
        //vetor de _m256d para armazenar os valores de entrada de cada linha
        //seu tamanho é 4 pois o número máximo de linhas da matriz é 4
        __m256d matriz1M256d[4];

        printf("Insira os valores do primeiro vetor\n");
        for(int i = 0; i < linhaMatriz1; i++){
            printf("Digite o valores linha %i: ", i+1);
            for(int j = 0; j < colunaMatriz1; j++){
                scanf("%lf", &matriz1[j]);
            }    
            matriz1M256d[i] = _mm256_setr_pd(matriz1[0],matriz1[1],matriz1[2],matriz1[3]);
        }

        double matriz2[4] = {0,0,0,0};
        __m256d matriz2M256d[4];
        printf("\nInsira os valores do segundo vetor\n");
        for(int i = 0; i < linhaMatriz2; i++){
            printf("Digite o valores linha %i: ", i+1);
            for(int j = 0; j < colunaMatriz2; j++){
                scanf("%lf", &matriz2[j]);
            }
            matriz2M256d[i] = _mm256_setr_pd(matriz2[0],matriz2[1],matriz2[2],matriz2[3]);
        }

        //Soma de cada linha das matrizes
        __m256d matrizResultadoM256d[4];
        matrizResultadoM256d[0] = _mm256_add_pd(matriz1M256d[0],matriz2M256d[0]);
        matrizResultadoM256d[1] = _mm256_add_pd(matriz1M256d[1],matriz2M256d[1]);
        matrizResultadoM256d[2] = _mm256_add_pd(matriz1M256d[2],matriz2M256d[2]);
        matrizResultadoM256d[3] = _mm256_add_pd(matriz1M256d[3],matriz2M256d[3]);

        double* matrizResultado[4];
        matrizResultado[0] = (double*)&matrizResultadoM256d[0];
        matrizResultado[1] = (double*)&matrizResultadoM256d[1];
        matrizResultado[2] = (double*)&matrizResultadoM256d[2];
        matrizResultado[3] = (double*)&matrizResultadoM256d[3];

        printf("Matriz resultante da soma\n");
        for(int i = 0; i < linhaMatriz1; i++){
            for(int j = 0; j < colunaMatriz1; j++){
                printf(" %lf  ", matrizResultado[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("Erro.\nPara realizar a soma de duas matrizes, elas devem possuir o mesmo numero de linhas e colunas\n");
    }
}