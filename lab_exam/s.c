#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

// Queue structure
typedef struct
{
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void initializeQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);

int main()
{
    Queue q;
    initializeQueue(&q);

    // Demonstrating queue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}

// Function to initialize the queue
void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}

// Function to add an element to the queue
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0; // Set front to 0 if queue was empty
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1; // Return -1 if queue is empty
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        // Reset the queue if it becomes empty
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

// Function to display the queue elements
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
