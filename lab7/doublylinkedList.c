#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;

//--------------------creating doubly linked list---------------------------

struct node *create_dl(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (start == NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            new_node -> prev = NULL;
            new_node ->data = num;
            new_node ->next = NULL;
            start = new_node;
        }
        else{
            ptr = start;
            new_node = (struct node*)malloc(sizeof(struct node)); 
            new_node ->data = num;
            while (ptr ->next != NULL)
            {
                ptr = ptr ->next;
            }
            ptr ->next = new_node;
            new_node ->prev = ptr;
            new_node -> next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

//---------------------------display-------------------------------

void display(struct node *start){
    struct node *ptr;

    if (start == NULL)
    {
        printf("Linked List is empty\n"); 
        return;
    }
    
    ptr = start;
    printf("Doubly Linked List: ");

    while (ptr != NULL)
    {
        printf("%d ", ptr->data); 
        ptr = ptr->next;
    }
    printf("\n");
}

//---------------------------inserting-------------------------

struct node* inserting_at_beginning(struct node *start, int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data = val; 
    new_node ->prev = NULL;
    new_node -> next = start;
    if (start != NULL) 
        start -> prev = new_node;
    start = new_node;
    return start;
}

struct node* inserting_at_end(struct node *start, int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    new_node ->data = val;
    new_node ->next = NULL;
    ptr = start;
    while (ptr -> next != NULL)
    {
        ptr = ptr ->next;
    }
    ptr ->next = new_node;
    new_node ->prev = ptr;
    return start;
}

struct node* inserting_after_node(struct node *start, int val, int num){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    new_node -> data = val;
    ptr = start;
    while (ptr -> data != num)
    {
        ptr = ptr -> next;
    }
    new_node -> next = ptr ->next;
    new_node -> prev = ptr;
    ptr -> next = new_node;
    if (new_node -> next != NULL) 
        new_node -> next -> prev = new_node;
    return start;
}

struct node* inserting_before_node(struct node *start, int val, int num){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = start;

    new_node ->data = val;
    while (ptr ->data != num)
    {
        ptr = ptr -> next;
    }
    new_node -> next = ptr;
    new_node -> prev = ptr ->prev;
    ptr ->prev = new_node;
    if (new_node -> prev != NULL) 
        new_node -> prev -> next = new_node;
    else
        start = new_node; 
    return start;
}

//-----------------------deleting------------------------------

struct node* deleting_first_node(struct node *start){
    if (start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    
    struct node *ptr = start;
    start = start -> next;
    if (start != NULL) 
        start -> prev = NULL;
    printf("%d is got deleted", ptr-> data);
    free(ptr);
    return start;
}

struct node* deleting_last_node(struct node *start){
    if (start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    
    struct node *ptr = start;
    while (ptr -> next != NULL)
    {
        ptr = ptr ->next;
    }
    if (ptr -> prev != NULL) 
        ptr -> prev -> next = NULL;
    else
        start = NULL; 
    printf("%d is got deleted", ptr-> data);
    free(ptr);
    return start;    
}

struct node* deleting_after_a_node(struct node *start, int num){
    if (start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    struct node *ptr = start;
    struct node *temp;
    while (ptr -> data != num)
    {
        ptr = ptr ->next;
    }
    temp = ptr -> next;
    if (temp == NULL) {
        printf("No node exists after %d\n", num);
        return start;
    }
    ptr -> next = temp -> next;
    if (temp -> next != NULL) 
        temp -> next -> prev = ptr;
    printf("%d is got deleted", temp -> data);
    free(temp);
    return start;
}

struct node* deleting_before_a_node(struct node *start, int num){
    if (start == NULL)
    {
        printf("Underflow\n");
        return start;
    }
    struct node *ptr, *temp;
    ptr = start;
    while (ptr -> data != num)
    {
        ptr = ptr -> next;
    }
    temp = ptr -> prev;
    if (temp == NULL) {
        printf("No node exists before %d\n", num);
        return start;
    }
    if (temp -> prev != NULL) 
        temp -> prev -> next = ptr;
    else
        start = ptr; 
    ptr -> prev = temp -> prev;
    printf("%d is got deleted", temp -> data);
    free(temp);
    return start;
}

//-----------------------main function--------------------------

int main() {
    int choice, value, ref;
    printf("Doubly Linked List Menu:\n");

    do {
        printf("\n1. Create Doubly Linked List\n2. Display List\n3. Insert at Beginning\n4. Insert at End\n");
        printf("5. Insert After a Node\n6. Insert Before a Node\n7. Delete First Node\n8. Delete Last Node\n");
        printf("9. Delete After a Node\n10. Delete Before a Node\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            start = create_dl(start);
            break;

        case 2:
            display(start);
            break;

        case 3:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            start = inserting_at_beginning(start, value);
            break;

        case 4:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            start = inserting_at_end(start, value);
            break;

        case 5:
            printf("Enter reference node value: ");
            scanf("%d", &ref);
            printf("Enter value to insert after %d: ", ref);
            scanf("%d", &value);
            start = inserting_after_node(start, value, ref);
            break;

        case 6:
            printf("Enter reference node value: ");
            scanf("%d", &ref);
            printf("Enter value to insert before %d: ", ref);
            scanf("%d", &value);
            start = inserting_before_node(start, value, ref);
            break;

        case 7:
            start = deleting_first_node(start);
            break;

        case 8:
            start = deleting_last_node(start);
            break;

        case 9:
            printf("Enter node value after which to delete: ");
            scanf("%d", &ref);
            start = deleting_after_a_node(start, ref);
            break;

        case 10:
            printf("Enter node value before which to delete: ");
            scanf("%d", &ref);
            start = deleting_before_a_node(start, ref);
            break;

        case 11:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 11);

    return 0;
}