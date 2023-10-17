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

// 걱정 : del에 대입하고 free해도 먹힐까?
bool Delete(Node **head, int d) {
    Node *curr = (Node *)malloc(sizeof(Node));
    if (d == (*head)->value) curr = *head;
    else curr = Search(*head, d);

    Node *suc = FindSuccessor(curr);
    if (suc == NULL) {
        free(curr);
        return true;
    }
    else {
        if (Delete(head, suc->value)) {
            curr->value = suc->value;
            return true;
        } else return false;
    }

    if (d == (*head)->value) {
        Node *suc = FindSuccessor(*head);
        while (suc->left) suc = suc->left;
        
        int val = suc->value;
        if (Delete(head, val)) {
            (*head)->value = val;
            return true;
        } else return false;
    }
    else {
        Node *curr = Search(*head, d);
        Node *suc = FindSuccessor(curr);
        if (suc == NULL) {

        }
    }

}

Node *FindSuccessor(Node *curr) {
    if (curr->right) {
        curr = curr->right;
        while (curr->left) curr = curr->left;
        return curr;
    }
    else if (curr->left) {
        curr = curr->left;
        while (curr->right) curr = curr->right;
        return curr;
    }
    else return NULL;
}