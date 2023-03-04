#include<stdio.h>
#include <immintrin.h>

int main() {

    // Ler o código a ser criptografado a partir do arquivo "TextoPuro.txt";
    FILE* arquivo;
    char letra;
    //Recupera os caracteres do texto
    arquivo = fopen("TextoPuro.txt", "r");
    char vetor[32];
    int i = 0;
    while( (letra = getc(arquivo)) != EOF && i < 32) {
        vetor[i] = ("%c",letra);
        i++;
    }
    fclose(arquivo);

    //armazena os caracteres no vetor AVX
    __m256i vetorCifra = _mm256_setr_epi8(vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5], vetor[6], vetor[7],
                        vetor[8], vetor[9], vetor[10], vetor[11], vetor[12], vetor[13], vetor[14], vetor[15], vetor[16],
                        vetor[17], vetor[18], vetor[19], vetor[20], vetor[21], vetor[22], vetor[23], vetor[24], vetor[25],
                        vetor[26], vetor[27], vetor[28], vetor[29], vetor[30], vetor[31]);
    __m256i vetorEscalar = _mm256_set1_epi8(3);

    //soma três a todos elementos do vetor, realizando a criptografia de cesar
    vetorCifra = _mm256_add_epi8(vetorCifra, vetorEscalar);
    printf("\nValores do vetor com cifra de Cesar\n");
    char* vetorDeChar = (char*)&vetorCifra;
    for(int i = 0; i < 32; i++){
        printf("%c", vetorDeChar[i]);
    }
    printf("\n");

    //Permuta o vetor que foi criptografado
    printf("\nVetor permutado\n");
    __m256i vetorPermutado = _mm256_permute4x64_epi64(vetorCifra, 0b00110110);
    vetorDeChar = (char*)&vetorPermutado;
    for(int i = 0; i < 32; i++){
        printf("%c", vetorDeChar[i]);
    }
    printf("\n");

    //Armazena o texto que foi feito a criptografia
    arquivo = fopen("TextoCifrado.txt", "w");
    for(int i=0; i < 32; i++)
    {
        fputc(vetorDeChar[i], arquivo);    
    }
    fclose(arquivo);

    //Recupera o texto que foi criptografado
    printf("\nVetor despermutado e descriptografado\n");
    vetorPermutado = _mm256_permute4x64_epi64(vetorCifra, 0b11100100);
    vetorEscalar = _mm256_set1_epi8(3);
    __m256i vetorDescriptografado = _mm256_sub_epi8(vetorPermutado, vetorEscalar);
    vetorDeChar = (char*)&vetorDescriptografado;
    for(int i = 0; i < 32; i++){
        printf("%c", vetorDeChar[i]);
    }

    //Armazena o texto que foi descriptografado em um arquivo texto
    arquivo = fopen("TextoDescriptografado.txt", "w");
    for(int i=0; i < 32; i++)
    {
        fputc(vetorDeChar[i], arquivo);    
    }
    fclose(arquivo);

    return 0;
}