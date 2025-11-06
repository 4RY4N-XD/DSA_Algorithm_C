#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

// ----------------creating the circular queue----------------------

struct node* create_cll(struct node* start){
    struct node *new_node, *ptr;
    int num;

    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL){
            new_node -> next = new_node; 
            start = new_node;
        }  
        else{
            ptr = start;
            while (ptr -> next != start)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new_node;
            new_node -> next = start;
        } 
        printf("Enter the data: ");
        scanf("%d", &num);   
    }
    return start;
}

// ----------------------display-------------------------------

void display(struct node *start){   
    struct node *ptr;

    if (start == NULL)
    {
        printf("Linked List is empty\n"); 
        return;
    }
    
    ptr = start;
    printf("Circular Linked List: ");

    do
    {
        printf("%d ", ptr-> data); 
        ptr = ptr ->next;
    } while (ptr != start);
    printf("\n");
}

// ---------------------insertion--------------------------

//insertion at the beginning
struct node* insert_at_beginning(struct node *start, int value){
    struct node *ptr;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = value;

    if (start == NULL) {
        new_node->next = new_node; 
        return new_node;
    }

    ptr = start;
    while (ptr ->next != start)
    {
        ptr = ptr -> next;
    }
    new_node -> next = start;
    ptr -> next = new_node;
    start = new_node;
    return start;
}

//insertion at the end
struct node* insert_at_end(struct node *start, int value){
    struct node *ptr;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = value;

    if (start == NULL) {
        new_node->next = new_node; 
        return new_node;
    }

    new_node -> next = start;
    ptr = start;
    while (ptr -> next != start)
    {
        ptr = ptr -> next;
    }
    ptr -> next = new_node;
    return start;
}

// --------------------deletion-----------------------------

//deleting the beginning
struct node* delete_first_node(struct node *start){
    struct node *ptr;

    if (start == NULL) return NULL;
    if (start->next == start) { 
        free(start);
        return NULL;
    }

    ptr = start;
    while (ptr -> next != start)
    {
        ptr = ptr -> next;
    }
    ptr -> next = start -> next;
    printf("The %d got deleted", start ->data);
    free(start);
    start = ptr -> next;
    return start;
}

//deleting the last
struct node* delete_last_node(struct node *start){
    struct node *ptr;
    struct node *preptr;

    if (start == NULL) return NULL; 
    if (start->next == start) { 
        free(start);
        return NULL;
    }

    ptr = start;
    while (ptr -> next != start)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = start;
    printf("The %d got deleted", start -> data);
    free(ptr);
    return start;
}

//----------------------main function-----------------------
int main(){
    int choice, value;
    printf("Linked List Menu: \n");

    do
    {
        printf("\n1. Create Circular Linked List\n2. Transverse Linked List\n3. Insert at the beginning\n4. Insert at the end\n5. Deleting the first node\n6. Deleting the last node\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create_cll(start); 
            break;
        
        case 2: 
            display(start); 
            break;

        case 3:
            printf("Inserting at the Beginning\n");
            printf("Enter the element which you want to insert: ");
            scanf("%d", &value);
            start = insert_at_beginning(start, value);
            break;

        case 4:
            printf("Inserting at the end\n");
            printf("Enter the element which you want to insert: ");
            scanf("%d", &value);
            start = insert_at_end(start, value);
            break;

        case 5:
            start = delete_first_node(start);
            break;

        case 6:
            start = delete_last_node(start);
            break;

        default:
            break;
        }

    } while (choice != 7);
    
    return 0;
}