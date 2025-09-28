#include <stdio.h>
#define MAX 5

int deQueue[MAX];
int front = -1;
int rear = -1;

//to check do queue is full
int isFull(){
    return (front == (rear + 1)%MAX);
}

//to check do queue is empty
int isEmpty(){
    return ((front == -1) && (rear == -1));
}

//Enqueue from Front
void enqueueFront(int num){
    if (isFull())
    {
        printf("Queue Overflow");
    }
    else if(isEmpty()){
        front = rear = 0;
    }
    // else if (front == 0)   
    // {
    //     front = MAX -1;
    // }
    // else{
    //     front --;
    // }
    else{
        front = (front - 1 + MAX)%MAX;
    }

    deQueue[front] = num;
}

//Enqueue from Rear
void enqueueRear(int num){
    if (isFull())
    {
        printf("Queue Overflow");
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else{
        rear = (rear + 1)%MAX; //u can either build logic by checking rear == MAX-1 and 
    }                         //make rear = 0 and finally default case of rear to increament that
    deQueue[rear] = num;
}

void display(){
    if (isEmpty)
    {
        printf("Queue is Empty");
    }
    printf("Queue contents: ");
    int i = front;
    while (1) {
        printf("%d ", deQueue[i]);
        if (i == rear) break;     // u can either put that in while but have to print rear manually at last, or either use do while
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void dequeueFront(){
    if (isEmpty())
    {
        printf("Queue Underflow");
    }
    
    int var = deQueue[front];
    printf("Element that deleted from front %d\n", var);
    if (front == rear)
    {
        front = rear = -1;
    }
    else{
        front = (front + 1)%MAX;
    }
}

void dequeueRear(){
    if (isEmpty())
    {
        printf("Queue Underflow");
    }
    
    int var = deQueue[rear];
    printf("Element that deleted from front %d\n", var);

    if (front == rear)
    {
        front = rear = -1;
    }
    else{
        rear = (rear -1 + MAX)%MAX;
    }   
}

int main() {
    int choice, value;

    printf("Double-Ended Circular Queue Menu\n");

    do {
        printf("\n1. Enqueue from Front\n2. Enqueue from Rear\n");
        printf("3. Dequeue from Front\n4. Dequeue from Rear\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}