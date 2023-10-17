#pragma once

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

Node *Build(int *nums, int from, int to);
int Minimum(Node *head);
int Maximum(Node *head);
Node *Search(Node *head, int q);


void Inorder(Node *head, int *inorder, int *i);
void Preorder(Node *head, int *preorder, int *i);
void Postorder(Node *head, int *postorder, int *i);

bool Insert(Node **head, int a);
bool Delete(Node **head, int d);
Node *FindSuccessor(Node *curr);