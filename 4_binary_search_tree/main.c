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

int Minimum(Node *head) {
    while (head->left) head = head->left;
    return head->value;
}

int Maximum(Node *head) {
    while (head->right) head = head->right;
    return head->value;
}

void Print_Tree(Node *head, int len) {
    int wid = (len + 1) / 2;
    int hei = sqrt(len + 1);

    char *form = (char *)malloc(sizeof(char) * wid);
    sprintf(form, "%%%dd\n", wid);
    printf(form, head->value);
    printf("  %d  %d\n", head->left->value, head->right->value);
    printf("%d  %d  %d  %d\n", head->left->left->value, head->left->right->value, head->right->left->value, head->right->right->value);
    printf("      %d       %d\n", head->left->right->right->value, head->right->right->right->value);
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
            Print_Tree(head, i);
           } else {
            printf("Build Error");
            return 1;
           } 
        }
        else if (c == 'm') {
            int m = Minimum(head);
            if (m) fprintf(outFile, "%d", m);
            else {
                printf("Minimum Finding Error");
                return 1;
            }
        }
        else if (c == 'M') {
            int M = Maximum(head);
            if (M) fprintf(outFile, "%d", M);
            else {
                printf("Maximum Finding Error");
                return 1;
            }
        }
        else  fputs("Function Error", outFile);
        fputc('\n', outFile);
    }
}