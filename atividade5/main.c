#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso correto: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char *words[100]; // Supondo que haverá no máximo 100 palavras
    int wordCount = 0;
    char word[100];

    while (fscanf(inputFile, "%s", word) != EOF) {
        words[wordCount] = strdup(word);
        wordCount++;
    }

    bubbleSort(words, wordCount);

    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Palavras ordenadas e salvas em %s\n", outputFileName);

    return 0;
}