#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

//Enqueue
void enqueue(int num){
    if(front == MAX -1){
        printf("Queue Overflow \n");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = num;
    }
    else{
        rear ++;
        queue[rear] = num;
    }
}

//Dequeue
void dequeue(){
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow \n");
    }
    else{
        printf("Dequeued element: %d", queue[front]);
        front ++;
    }
}

//Display
void display(){
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow \n");
    }
    else{
        printf("Elements in Queue: ");
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d  ", queue[i] );
        }
    }
}

//Peek
void peek(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow \n");
    }
    else{
        printf("Peek value: %d", queue[front]);
    }
}


int main(){
    int choice, value;
    printf("Stack Operations Menu\n");

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}