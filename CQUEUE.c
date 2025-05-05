#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Queue size

int cqueue[MAX];
int front = -1, rear = -1;

void cenqueue(int x) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is Full!\n");
        return;
    }
    else if (front == -1) {  // First element
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0) {  // Circular condition
        rear = 0;
    }
    else {
        rear++;
    }
    cqueue[rear] = x;
    printf("%d enqueued\n", x);
}

void cdequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    int x = cqueue[front];
    printf("%d dequeued\n", x);
    
    if (front == rear) {  // Last element
        front = rear = -1;
    }
    else if (front == MAX - 1) {  // Circular condition
        front = 0;
    }
    else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Circular Queue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    else {
        for (int i = front; i < MAX; i++)
            printf("%d ", cqueue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}

int main() {
    cenqueue(10);
    cenqueue(20);
    cenqueue(30);
    display();
    
    cdequeue();
    display();
    
    cenqueue(40);
    cenqueue(50);
    cenqueue(60);  // Will show "Queue is Full!"
    display();
    
    return 0;
}
