#include "main.h"

bool Insert(Node **head, int a) {
    if (!*head) {
        *head = (Node *)malloc(sizeof(Node));
        (*head)->value = a;
        (*head)->left = NULL;
        (*head)->right = NULL;
        return true;
    }
    else if (a == (*head)->value) return false;
    else if (a > (*head)->value) {
        if ((*head)->right) Insert(&((*head)->right), a);
        else {
            Node *n = (Node *)malloc(sizeof(Node));
            n->value = a;
            n->left = NULL;
            n->right = NULL;
            (*head)->right = n;
            return true;
        }
    }
    else {
        if ((*head)->left) Insert(&((*head)->left), a);
        else {
            Node *n = (Node *)malloc(sizeof(Node));
            n->value = a;
            n->left = NULL;
            n->right = NULL;
            (*head)->left = n; 
            return true;
        }
    }
    return true;
}