#include "main.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Correct Usage : [program] [input file] [output file]\n");
        return 1;
    } 

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");

    char c;
    int len = 0, i, j;
    Node *head = NULL;
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;
        if (c == 'B') {
           len = 0;
           int nums[30];
           while (fscanf(inFile, "%d", &nums[len]) == 1) {
            if ((len != 0) && (nums[len-1] > nums[len])) {
                printf("Enter the intergers in the ascending order\n");
                return 1;
            }
            len++;
           }

           head = Build(nums, 0, len-1);
           if (head != NULL) {
            fputs("B ", outFile);
           } else {
            printf("Build Error\n");
            return 1;
           } 
        }
        else if (c == 'm') {
            int m = Minimum(head);
            if (m) fprintf(outFile, "m %d", m);
            else {
                printf("Minimum Finding Error\n");
                return 1;
            }
        }
        else if (c == 'M') {
            int M = Maximum(head);
            if (M) fprintf(outFile, "M %d", M);
            else {
                printf("Maximum Finding Error\n");
                return 1;
            }
        }
        else if (c == 'S') {
            int q;
            fscanf(inFile, "%d", &q);
            Node *n = Search(head, q);
            if (n) fprintf(outFile, "S %d", n->value);
            else {
                printf("Search Error\n");
                return 1;
            }
        }
        else if (c == 'N') {
            if (len == 0) {
                fputs("N\n", outFile);
                continue;
            }

            int *inorder = (int *)malloc(sizeof(int) * len);
            i = 0;
            Inorder(head, inorder, &i);
            if (i == len) {
                fputc('N', outFile);
                for (j = 0; j < len; j++) fprintf(outFile, " %d", inorder[j]);
            } else {
                printf("i = %d, len = %d\n", i, len);
                printf("Inorder Traversal Error\n");
                return 1;
            }
            free(inorder);
        }
        else if (c == 'R') {
            if (len == 0) {
                fputs("R\n", outFile);
                continue;
            }

            int *preorder = (int *)malloc(sizeof(int) * len);
            i = 0;
            Preorder(head, preorder, &i);
            if (i == len) {
                fputc('R', outFile);
                for (j = 0; j < len; j++) fprintf(outFile, " %d", preorder[j]);
            }
            else {
                printf("Preorder Traversal Error\n");
                return 1;
            }
            free(preorder);
        }
        else if (c == 'O') {
            if (len == 0) {
                fputs("O\n", outFile);
                continue;
            }

            int *postorder = (int *)malloc(sizeof(int) * len);
            i = 0;
            Postorder(head, postorder, &i);
            if (i == len) {                                                                                                                                                                                                                                                                                                                                                                                    
                fputc('O', outFile);
                for (j = 0; j < len; j++) fprintf(outFile, " %d", postorder[j]);
            }
            else {
                printf("Postorder Traversal Error\n");
                return 1;
            }
            free(postorder);
        }
        else if (c == 'I') {
            int a;
            fscanf(inFile, "%d", &a);
            if (Insert(&head, a)) {
                len++;
                fprintf(outFile, "I %d", a);
            }
        }
        else if (c == 'D') {
            if (len == 0) {
                fputs("D : NO ELEMENT ERROR", outFile);
                continue;
            }

            int d;
            fscanf(inFile, "%d", &d);
            if (Delete(&head, d)) {
                len--;
                fprintf(outFile, "D %d", d);
            }
        }
        else  fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    free(head);
    fclose(inFile);
    fclose(outFile);
}