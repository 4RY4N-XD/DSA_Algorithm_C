#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
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

// Queue structure for level-order insertion
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Queue operations
void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear) {
        q->rear->next = temp;
        q->rear = temp;
    } else {
        q->front = q->rear = temp;
    }
}

struct Node* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Insert node into general binary tree using level-order
void insert(struct Node** root, int value) {
    struct Node* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Queue q = {NULL, NULL};
    enqueue(&q, *root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        if (!temp->left) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&q, temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&q, temp->right);
        }
    }
}

// In-order traversal to print the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Free memory (post-order)
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to test the tree
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("In-order traversal of the binary tree:\n");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}