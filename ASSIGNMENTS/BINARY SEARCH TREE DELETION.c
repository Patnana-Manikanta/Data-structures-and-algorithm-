#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node *findMin(struct Node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int value, int *deleted) {

    if (root == NULL)
        return NULL;

    if (value < root->data) {
        root->left = deleteNode(root->left, value, deleted);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value, deleted);
    }
    else {

        *deleted = 1;

        // Case 0: No child
        if (root->left == NULL && root->right == NULL) {
            printf("Case 0: Leaf node deleted\n");

            free(root);
            return NULL;
        }

        // Case 1: Only right child
        else if (root->left == NULL) {
            printf("Case 1: Node with only right child deleted\n");

            struct Node *temp = root->right;

            free(root);
            return temp;
        }

        // Case 1: Only left child
        else if (root->right == NULL) {
            printf("Case 1: Node with only left child deleted\n");

            struct Node *temp = root->left;

            free(root);
            return temp;
        }

        // Case 2: Two children
        else {
            printf("Case 2: Node with two children\n");

            struct Node *temp = findMin(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data, deleted);
        }
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    int n, value, deleteValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder before deletion: ");
    inorder(root);

    while (1) {

        printf("\n\nEnter value to delete (-1 to exit): ");
        scanf("%d", &deleteValue);

        if (deleteValue == -1)
            break;

        int deleted = 0;

        printf("Inorder before: ");
        inorder(root);

        printf("\n");

        root = deleteNode(root, deleteValue, &deleted);

        if (!deleted)
            printf("Node %d not found in the BST.\n", deleteValue);

        printf("Inorder after: ");
        inorder(root);

        printf("\n");
    }

    return 0;
}
