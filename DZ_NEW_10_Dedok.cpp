#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE* inputFile, * outputFile;
    char fileName[] = "input_1.txt";
    char outputFileName[] = "output_1.txt";

    if ((inputFile = fopen(fileName, "r")) == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    if ((outputFile = fopen(outputFileName, "w")) == NULL) {
        printf("Cannot open output file.\n");
        fclose(inputFile);
        return 1;
    }

    char buffer[1000];
    char prevLine[1000] = "";

    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        if (prevLine[0] != '\0') {
            fprintf(outputFile, "%s", prevLine);
        }
        strcpy(prevLine, buffer);
    }

    fclose(inputFile);
    fclose(outputFile);

    FILE* inputFile_1, * outputFile_1;
    char fileName_1[] = "input_1.txt";
    char outputFileName_1[] = "output_2.txt";

    if ((inputFile_1 = fopen(fileName_1, "r")) == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    if ((outputFile_1 = fopen(outputFileName_1, "w")) == NULL) {
        printf("Cannot open output file.\n");
        fclose(inputFile_1);
        return 1;
    }

    char buffer_1[1000];
    int lineNumber = 1;

    while (fgets(buffer_1, sizeof(buffer_1), inputFile_1) != NULL) {
        if (lineNumber % 2 != 0) {
            fprintf(outputFile_1, "%s", buffer_1);
        }
        lineNumber++;
    }
    fclose(inputFile_1);
    fclose(outputFile_1);
    return 0;
}
