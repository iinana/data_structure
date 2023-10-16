#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct NODE {
    int value;
    struct NODE *left;
    struct NODE *right;
} Node;

Node *Build(int *nums, int from, int to) {
    if (from > to) return NULL;

    Node *head = (Node *)malloc(sizeof(Node));
    int mid = (from + to) / 2;

    head->value = nums[mid];
    head->left = Build(nums, from, mid-1);
    head->right = Build(nums, mid+1, to);

    return head;
}

void Print_Tree(Node *head, int len) {
    int wid = (len + 1) / 2;
    int hei = sqrt(len + 1);

    char *form = (char *)malloc(sizeof(char) * wid);
    sprintf(form, "%%%dd", wid);
    printf(form, head->value);

    Node *left = (Node *)malloc(sizeof(Node));
    Node *right = (Node *)malloc(sizeof(Node));
    for (int i = 1; i < hei; i++) {
        for (int j = 1; j <= wid; j *= 2) {
            for (int x1 = 0; x1 < j/2; x1 += 2) {
                printf("%d %d", head.left.left, head.left.right)
            } 
        }
        head = head.left;
    }

}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Correct Usage : [program] [input file] [output file]");
        return 1;
    } 

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");

    char c;
    Node *head = (Node *)malloc(sizeof(Node));
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;
        if (c == 'B') {
           int nums[30];
           int i = 0;
           char num[10];
           while ((c = fgetc(inFile)) != '\n') {
            fscanf(inFile, "%s", num);
            nums[i] = atoi(num);

            if ((i != 0) && (nums[i-1] > nums[i])) {
                printf("Enter the intergers in the ascending order");
                return 1;
            }

            i++;
           }
           head = Build(nums, 0, i-1);
           if (head != NULL) {
            fputs("B ", outFile);
            for (int j = 0; j < i; j++) {
                fprintf(outFile, "%d ", nums[j]);
            } 
           } else fputs("Build Error", outFile);
        }
        // else if (c == 'm')
        // else if (c == 'M')
        else  fputs("Function Erorr", outFile);
        fputc('\n', outFile);
    }
}