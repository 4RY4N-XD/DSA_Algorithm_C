#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node *);
void traverse(struct node *);
struct node *push(struct node *, int);
struct node *pop(struct node *);

//-------------------------Create Stack-----------------------------
struct node *create(struct node *start) {
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        start = push(start, num);  // Use push to maintain LIFO order
        printf("Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

//--------------------------Traverse The Stack---------------------------------
void traverse(struct node *start) {
    struct node *ptr = start;
    printf("\nStack: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

//---------------------------Push--------------------------------
struct node *push(struct node *start, int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = start;
    start = new_node;
    return start;
}

//--------------------------Pop----------------------------------
struct node *pop(struct node *start) {
    if (start == NULL) {
        printf("UnderFlow\n");
        return NULL;
    }
    struct node *temp = start;
    start = start->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
    return start;
}

//------------------------Main Menu-----------------------
int main() {
    int choice, value;
    printf("Stack Using Linked List\n");

    do {
        printf("\n1. Create Stack\n2. Display Stack\n3. Push\n4. Pop\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            start = create(start);
            break;
        case 2:
            traverse(start);
            break;
        case 3:
            printf("Enter value to push: ");
            scanf("%d", &value);
            start = push(start, value);
            break;
        case 4:
            start = pop(start);
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