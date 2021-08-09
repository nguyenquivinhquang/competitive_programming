#include <bits/stdc++.h>

using namespace std;
struct Node {
    int key;
    Node *left;
    Node *right;
};
Node *createNode(int x) {
    Node *newNode = new Node;
    newNode->key = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *insertNode(Node *root, int x) {
    if (root == NULL)
        return createNode(x);
    if (x < root->key)
        root->left = insertNode(root->left, x);
    else if (x > root->key)
        root->right = insertNode(root->right, x);

    return root;
}
void createTree(Node *&root, int a[], int n) {
    for (int i = 0; i < n; i++)
        root = insertNode(root, a[i]);
}
Node *searchNode(Node *root, int x) {
    if (root == NULL || root->key == x)
        return root;
    if (root->key < x)
        return searchNode(root->right, x);
    return searchNode(root->left, x);
}
int main() {
}