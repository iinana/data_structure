#include "main.h"

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

Node *Search(Node *head, int q) {
    if (!head) return NULL;
    else if (q == head->value) return head;
    
    if (q < head->value) Search(head->left, q);
    else if (q > head->value) Search(head->right, q);
}