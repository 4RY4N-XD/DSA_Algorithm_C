#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node*);

//-------------------------Create Linked List-----------------------------
struct node *create(struct node *start){   //* in the function becoz we are 
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL){
            new_node -> next = NULL;
            start = new_node;
        }  
        else{
            ptr = start;
            while (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new_node;
            new_node -> next = NULL;
        } 
        printf("Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

//--------------------------Transverse The Linked List---------------------------------
void transverse(struct node *start){
    struct node *ptr = start;
    printf("\nLinked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
};


//-------------------------Search in the Linked List------------------------------
int search(struct node *start, int target){
    struct node *ptr = start;
    int position = 0;

    while (ptr != NULL)
    {
        if (ptr -> data == target)
        {
            return position;
        }
        else{
            ptr = ptr -> next;
            position ++;
        }
    }
    return -1;
}

//-------------------------Inserting in the Linked List---------------------------------

//new node at the beginning

struct node *insert_at_beginning(struct node *start, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = value;
    new_node -> next = start;

    start = new_node;
    return start;
}

//new node at the end

struct node *insert_at_end(struct node *start, int value){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node* ptr;

    new_node -> data = value;
    new_node -> next = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else{
        ptr = start;
        while (ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = new_node;
    }
    return start;
};

//new node after a given node

struct node *insert_after_given_node(struct node *start, int value, int target) {
    if (start == NULL) {
        printf("Error: List is empty.\n");
        return start;
    }

    struct node *ptr = start;
    while (ptr != NULL && ptr->data != target) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Error: Target node with value %d not found.\n", target);
        return start;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = value;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return start;
}

//new node before a given node

struct node *insert_before_given_node(struct node *start, int value, int target) {
    if (start == NULL) {
        printf("Error: List is empty\n");
        return start;
    }

    // Case: target is in the first node
    if (start->data == target) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = start;
        start = new_node;
        return start;
    }

    // Traverse to find node before target
    struct node *ptr = start;
    while (ptr->next != NULL && ptr->next->data != target) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        printf("Error: Target node with value %d not found.\n", target);
        return start;
    }

    // Insert before target
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return start;
}


//------------------------------Main Function------------------------------------------
int main() {
    int choice, value, target;
    printf("Linked List Menu: \n");

    do
    {
        printf("\n1. Create Linked List\n2. Transverse Linked List\n3. Search in the Linked List\n4. Insert at the beginning\n5. Insert at the end\n6. Insert after a given node\n7. Insert before a given node\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create(start); 
            break;
        
        case 2: 
            transverse(start); 
            break;

        case 3:
            printf("Enter the number which you want to search: ");
            scanf("%d", &target);
            int pos = search(start, target);
            printf("Your target is at postion %d", pos);
            break;

        case 4: 
            printf("Inserting at the Beginning\n");
            printf("Enter the element which you want to insert: ");
            scanf("%d", &value);
            start = insert_at_beginning(start, value);

        case 5:
            printf("Inserting at the end\n");
            printf("Enter the element which you want to insert: ");
            scanf("%d", &value);
            start = insert_at_end(start, value);

        case 6:
            printf("Enter the element after which you want to insert: ");
            scanf("%d", &target);
            printf("Enter the value which you want to insert: ");
            scanf("%d", &value);
            start = insert_after_given_node(start, value, target);

        case 7:
            printf("Enter the element before which you want to insert: ");
            scanf("%d", &target);
            printf("Enter the value which you want to insert: ");
            scanf("%d", &value);
            start = insert_before_given_node(start, value, target);

        default:
            break;
        }


    } while (choice != 8);
    


    return 0;
}
