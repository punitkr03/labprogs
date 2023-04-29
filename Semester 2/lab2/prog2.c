// Implement a Queue using structures
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue
{
    int arr[MAX];
    int front;
    int rear;
} Q;

int isFull(Q *q)
{
    return (q->front == -1 && q->rear == -1) ? 0 : 1;
}

int isEmpty(Q *q)
{
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

void enqueue(Q *q, int item)
{

    if (!isFull(q))
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = item;
        printf("%d is added to queue.\n", q->arr[q->rear]);
    }
    else if (q->rear >= 99)
    {
        printf("Queue Overflow!");
    }
    else
    {
        q->arr[++q->rear] = item;
        printf("%d is added to queue.\n", q->arr[q->rear]);
    }
}

void dequeue(Q *q)
{
    if (isEmpty(q))
        printf("Queue Underflow!");
    else
        printf("%d is removed from queue.\n", q->arr[q->front++]);
}

void peek(Q *q)
{
    printf("%d", q->arr[q->front]);
}

int main()
{
    Q q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    dequeue(&q);
    enqueue(&q, 4);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 5);

    while (q.front <= q.rear)
        dequeue(&q);

    return 0;
}