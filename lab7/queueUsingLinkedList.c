#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

//-------------------------Create Queue-----------------------------
void create() {
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        new_node->data = num;
        new_node->next = NULL;

        if (front == NULL) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }

        printf("Enter the data: ");
        scanf("%d", &num);
    }
}

//--------------------------Display Queue---------------------------------
void display() {
    struct node *ptr = front;
    printf("\nQueue: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

//---------------------------Enqueue--------------------------------
void enqueue(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

//--------------------------Dequeue----------------------------------
void dequeue() {
    if (front == NULL) {
        printf("UnderFlow\n");
        return;
    }

    struct node *temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

//------------------------Main Menu-----------------------
int main() {
    int choice, value;
    printf("Queue Using Linked List\n");

    do {
        printf("\n1. Create Queue\n2. Display Queue\n3. Enqueue\n4. Dequeue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}