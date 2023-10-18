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

// 걱정 : del에 대입하고 free해도 먹힐까? - 안먹힌다 어케 해결하지
bool Delete(Node **head, int d) {
    Node *par = (Node *)malloc(sizeof(Node));
    Node *del = *head;

    if (!Find_Par_Del(&par, &del, d)) return false;

    Node *suc = Find_Successor(del);
    if (suc == NULL) {
        if (del == *head) {
            free(*head);
            return true;
        }
        if ((par->left) && (par->left->value == d)) {
            par->left = NULL;
            free(del);
            return true;
        } 
        else if ((par->right) && (par->right->value == d)) {
            par->right = NULL;
            free(del);
            return true;
        }
        else return false;
        
    }
    else {
        int val = suc->value;
        if (Delete(head, val)) {
            del->value = val;
            return true;
        } else return false;
    }
}

bool Find_Par_Del(Node **par, Node **del, int d) {
    if ((*del)->value == d) return true;

    if (d > (*del)->value) {
        if ((*del)->right) {
            *par = *del;
            *del = (*del)->right;
            return Find_Par_Del(par, del, d);
        }
        else return false;
    }
    else {
        if ((*del)->left) {
            *par = *del;
            *del = (*del)->left;
            return Find_Par_Del(par, del, d);
        }
        else return false;
    }
}

Node *Find_Successor(Node *del) {
    if (!(del->left || del->right)) return NULL;
    
    if (del->right) del = del->right;
    else return del->left;

    while (del->left) del = del->left;
    return del;
}