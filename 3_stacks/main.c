#include "main.h"
#include "stack.h"

int main(int argc, char **argv) {
    if (argc != 3)
    {
        printf("Correct Usage : [Program] [Input File] [Output File]");
        return 0;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    if ((inFile == NULL) || (outFile == NULL)) {
        printf("Failed to Open File");
        return 0;
    }

    char c;
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;

        if (c == 'P') {
            char word[50];
            fscanf(inFile, "%s", word);

            if (isPalindrome(word, strlen(word))) fputc('T', outFile);
            else fputc('F', outFile);
        } 
        else if (c == 'B') {
            char word[50];
            fscanf(inFile, "%s", word);

            if (isBalanced(word, strlen(word))) fputc('T', outFile);
            else fputc('F', outFile);
        } 
        else fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    fclose(inFile);
    fclose(outFile);
    return 0;
}