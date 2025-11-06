#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

//-------------------------Create Linked List-----------------------------
struct node *create(struct node *start){   // * in the function becoz we are 
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
void traverse(struct node *start) {
    struct node *ptr = start;
    printf("\nLinked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

//--------------------------Deleting in the Linked List--------------------------------

//deleting the first node
struct node *deletingFirstNode(struct node *start){
    if (start == NULL)
    {
        printf("UnderFlow\n");
        return NULL;
    }
    
    struct node *temp = start;
    start = start -> next;

    printf("Deleted element is %d \n", temp -> data);
    free(temp);

    return start;
}

//deleting the last node
struct node *delete_last_node(struct node *start) {
    if (start == NULL) {
        printf("UnderFlow\n");
        return NULL;
    }

    // Case: only one node
    if (start->next == NULL) {
        printf("Deleting last node with value %d\n", start->data);
        free(start);
        return NULL;
    }

    // Traverse to second-last node
    struct node *ptr = start;  //ptr as preptr
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    printf("Deleting last node with value %d\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;

    return start;
}

//deleting after a given node
struct node* deletingAfterGivenNode(struct node* start, int target) {
    if (start == NULL) {
        printf("UnderFlow\n");
        return NULL;
    }

    // Case: only one node
    if (start->next == NULL) {
        printf("There is no node after this\n");
        return start;
    }

    struct node* ptr = start;

    // Traverse to the target node
    while (ptr != NULL && ptr->data != target) {
        ptr = ptr->next;
    }

    // If target not found
    if (ptr == NULL) {
        printf("Target node not found\n");
        return start;
    }

    // If there's no node after target
    if (ptr->next == NULL) {
        printf("No node exists after target %d\n", target);
        return start;
    }

    printf("Deleting the node after your desired target %d\n", ptr->next->data);
    struct node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return start;
}




//------------------------------Main Function------------------------------------------
int main() {
    int choice, target;
    printf("Linked List Menu: \n");

    do
    {
        printf("\n1. Create Linked List\n2. Transverse Linked List\n3. Deleting First node of Linked List\n4. Deleting the last node\n5. Deleting after a given target\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create(start); 
            break;
        
        case 2: 
            traverse(start); 
            break;

        case 3:
            start = deletingFirstNode(start);
            break;

        case 4: 
            start = delete_last_node(start);
            break;

        case 5:
            printf("Deleting after a the given element\n");
            printf("Enter the element after which you want to delete the element: ");
            scanf("%d", &target);
            start = deletingAfterGivenNode(start, target);


        default:
            break;
        }


    } while (choice != 6);
    


    return 0;
}
