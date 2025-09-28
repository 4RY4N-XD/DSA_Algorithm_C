#include <stdio.h>
#define MAX_PRIORITY 3
#define MAX_SIZE 5

int priorityQueue[MAX_PRIORITY][MAX_SIZE];
int front [MAX_PRIORITY];
int rear [MAX_PRIORITY];

//Initialize all queues of all priority
void initialize(){
    for (int i = 0; i < MAX_PRIORITY; i++)
    {
        front[i] = rear[i] = -1;
    }
}

//Check do queue is full
int isFull(int p){
    return(front[p] == (rear[p] + 1)%MAX_SIZE);
}

//Check do queue is empty
int isEmpty(int p){
    return(front[p] == -1);
}

//Enqueue
void enqueue(int num, int p){
    if (p < 0 || p >= MAX_PRIORITY)
    {
        printf("Invalid Priority");
        return;
    }
    if (isFull(p))
    {
        printf("Queue Overloaded");
        return;
    }
    if (isEmpty(p))
    {
        rear[p] = front[p] = 0;
    }
    else{
        rear[p] = (rear[p]+1)%MAX_SIZE;
    }
    priorityQueue[p][rear[p]] = num;
    printf("Inserted %d at the priority %d\n", num, p);
}

//dequeue - remove first non empty one of highest priority (0)
void dequeue(){
    for (int i = 0; i < MAX_PRIORITY; i++)
    {
        if (!isEmpty(i))
        {
            int value = priorityQueue[i][front[i]];
            if (front[i] == rear[i])
            {
                front[i] = rear[i] = -1;
            }
            else{
                front[i] = (front[i] + 1)%MAX_SIZE;
            }
            printf("Deleted %d at the priority %d\n", value, i);
            return;
        }
    }
    printf("Queue at all priorities is empty");
}

//display
void display(){
    for (int p = 0; p < MAX_PRIORITY; p++)
    {
        if (isEmpty(p))
        {
            printf("Empty \n");
            continue;
        }
        int i = front[p];
        while (1)
        {
            printf("%d ", priorityQueue[p][i]);
            if (front[i] == rear[i])
            {
                break;
            }
            i = (i+1)%MAX_SIZE;
        }
        printf("\n");
    }
    
}

//peek 
void peek(){
    for (int i = 0; i < MAX_PRIORITY; i++)
    {
        /* code */
    }
    
}

int main() {
    int choice, value, priority;
    initialize();  // Initialize all queues

    printf("Priority Queue Operations Menu\n");

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                printf("Enter priority (0 to %d): ", MAX_PRIORITY - 1);
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}