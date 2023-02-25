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
            printf("O valor minimo para uma linha ou coluna e de 1 e o valor maximo e de 4");
        }
    }while(!(linhaMatriz1 >= 1 && linhaMatriz1 <=4) && !(colunaMatriz1 >= 1 && colunaMatriz1 <=4));
    
    
    int linhaMatriz2 = 1;
    int colunaMatriz2 = 1;
    do{
        printf("Digite a quantidade de linhas e colunas da segunda matriz: ");
        scanf("%d %d", &linhaMatriz2, &colunaMatriz2);
        if(!(linhaMatriz2 >= 1 && linhaMatriz2 <=4) && !(colunaMatriz2 >= 1 && colunaMatriz2 <=4)){
            printf("O valor minimo para uma linha ou coluna e de 1 e o valor maximo e de 4");
        }
    }while((linhaMatriz2 >= 1 && linhaMatriz2 <=4) && (colunaMatriz2 >= 1 && colunaMatriz2 <=4));

    if(linhaMatriz2 == colunaMatriz1){
        
    }else{
        printf("Erro. Para fazer a multiplicacao a quantidade de colunas da primeira matriz deve ser igual a quantidade de linhas da segunda matriz");
    }
}