#include <stdio.h>
#define MAX 4

int circularQueue[MAX];
int front = -1;
int rear = -1;

//Enqueue
void enqueue(int num){
    if ((front == 0 && rear == MAX -1) || (rear == front -1)) //u can either use (rear+1)%MAX == front
    {
        printf("Queue Overflow \n");
        return; //bcoz it keep adding even after it reach to MAX idk why but there is smthg like it adding to place after circularQueue array
    }
    if (front == -1 && rear == -1)
    {
        rear = front = 0;
    }
    else if (rear == MAX -1 && front != 0){
        rear = 0;
    }
    else{
        rear ++;
    }
    circularQueue[rear] = num;
}

//Dequeue
void dequeue(){
    if (front == -1)
    {
        printf("Queue Underflow \n");
    }
    int val = circularQueue[front];
    printf("Dequeued element: %d \n", val );
    if (front == rear)
    {
        front = rear = -1;
    }
    else{
        if (front == MAX -1)
        {
            front = 0;
        }
        else{
            front ++;
        }
        
    }  
}

//display
void display(){
    if (front == -1)
    {
        printf("Queue Underflow \n");
    }
    else{
        printf("Elements in Queue: ");
        int i = front;
        while (1)
        {
            printf("%d ", circularQueue[i]);    //u can either do this with i = (i + 1)%MAX for increment of i, if while condition work on i 
            if (i == rear)
            {
                break;
            }
            i++;
            if (i == MAX)
            {
                i = 0;
            }
            
        }
        
    }
    
}

//peek
void peek(){
    if (front == -1)
    {
        printf("Queue Underflow \n");
    }
    else{
        printf("Peek element: %d", circularQueue[front]);
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