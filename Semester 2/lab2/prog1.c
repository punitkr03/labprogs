// Implement a stack using arrays
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct stack
{
    int items[MAX_SIZE];
    int top;
} S;

// function to initialize the stack
void init(S *s)
{
    s->top = -1;
}

// function to check if the stack is empty
bool isEmpty(S *s)
{
    return (s->top == -1);
}

// function to check if the stack is full
bool isFull(S *s)
{
    return (s->top == MAX_SIZE - 1);
}

// function to push an item onto the stack
void push(S *s, int item)
{
    if (isFull(s))
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        s->items[++(s->top)] = item;
        printf("%d is pushed.\n", item);
    }
}

// function to pop an item from the stack
void pop(S *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    else
    {
        int val = s->items[s->top--];
        printf("%d is popped.\n", val);
    }
}
// function to peek into stack
void peek(S *s)
{
    printf("%d\n", s->items[s->top]);
}

int main()
{
    S s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    pop(&s);
    push(&s, 4);
    pop(&s);
    push(&s, 5);
    while (s.top != -1)
        pop(&s);

    return 0;
}
