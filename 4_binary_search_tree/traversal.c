#include "main.h"

void Inorder(Node *head, int *inorder, int *i) {
    if (!head->left) {
        inorder[*i] = head->value;
        ++(*i);
        if (head->right) Inorder(head->right, inorder, i);
        return;
    }

    Inorder(head->left, inorder, i);
    inorder[*i] = head->value;
    ++(*i);
    if (head->right) Inorder(head->right, inorder, i);
}

void Preorder(Node *head, int *preorder, int *i) {
    if (!head->left) {
        preorder[*i] = head->value;
        ++(*i);

        if (head->right) Preorder(head->right, preorder, i);
        return;
    }

    preorder[*i] = head->value;
    ++(*i);
    Preorder(head->left, preorder, i);
    if (head->right) Preorder(head->right, preorder, i);
}

void Postorder(Node *head, int *postorder, int *i) {
    if ((!head->left) || (!head->right)) {
        if (head->left) Postorder(head->left, postorder, i);
        else if (head->right) Postorder(head->right, postorder, i);

        postorder[*i] = head->value;
        ++(*i);
        return;
    } 

    Postorder(head->left, postorder, i);
    Postorder(head->right, postorder, i);
    postorder[*i] = head->value;
    ++(*i);
}