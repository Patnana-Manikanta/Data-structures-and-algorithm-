#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->id = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->id)
        root->left = insert(root->left, value);
    else if (value > root->id)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->id);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->id);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->id);
    }
}

int search(struct Node *root, int value) {
    if (root == NULL)
        return 0;

    if (root->id == value)
        return 1;

    if (value < root->id)
        return search(root->left, value);

    return search(root->right, value);
}

int main() {
    struct Node *root = NULL;

    int n, value, key;

    printf("Enter number of identification numbers: ");
    scanf("%d", &n);

    printf("Enter unique IDs:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter ID to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("ID %d exists in the BST.\n", key);
    else
        printf("ID %d does not exist in the BST.\n", key);

    return 0;
}
