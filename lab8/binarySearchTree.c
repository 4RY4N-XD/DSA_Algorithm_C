#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search in BST
struct Node* searchElement(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return searchElement(root->left, value);
    else
        return searchElement(root->right, value);
}

// Find largest node in left subtree
struct Node* findLargestNode(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Delete node from BST
struct Node* deleteElement(struct Node* root, int value) {
    if (root == NULL) {
        printf("Value not found in the tree\n");
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteElement(root->left, value);
    } else if (value > root->data) {
        root->right = deleteElement(root->right, value);
    } else {
        // Node found
        if (root->left != NULL && root->right != NULL) {
            struct Node* temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = deleteElement(root->left, temp->data);
        } else {
            struct Node* temp = root;
            if (root->left == NULL && root->right == NULL) {
                root = NULL;
            } else if (root->left != NULL) {
                root = root->left;
            } else {
                root = root->right;
            }
            free(temp);
        }
    }
    return root;
}

// Free memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main menu
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert values\n");
        printf("2. Display In-order Traversal\n");
        printf("3. Search for a value\n");
        printf("4. Delete a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter values to insert (-1 to stop):\n");
            while (1) {
                scanf("%d", &value);
                if (value == -1) break;
                root = insert(root, value);
            }
            break;

        case 2:
            printf("In-order Traversal:\n");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (searchElement(root, value))
                printf("%d found in the tree.\n", value);
            else
                printf("%d not found in the tree.\n", value);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteElement(root, value);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    freeTree(root);
    return 0;
}