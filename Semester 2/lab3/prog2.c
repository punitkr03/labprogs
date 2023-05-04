// C program to evaluate value of a postfix
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
typedef struct Stack
{
    int top;
    int size;
    int *array;
} S;

// Stack Operations
S *createStack(int size)
{
    S *stack = (S *)malloc(sizeof(S));
    stack->top = -1;
    stack->size = size;
    stack->array = (int *)malloc(stack->size * sizeof(int));

    return stack;
}

int isEmpty(S *stack)
{
    return stack->top == -1;
}

int isFull(S *stack)
{
    return stack->top == stack->size - 1;
}

int pop(S *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1;
}

void push(S *stack, int op)
{
    if (!isFull(stack))
        stack->array[++stack->top] = op;
    else
        printf("Stack Overflow!\n");
}

int evaluatePostfix(char *exp)
{
    S *stack = createStack(strlen(exp));
    int i;
    // Scan all characters one by one
    for (i = 0; exp[i]; i++)
    {
        if (exp[i] == ' ')
            continue;
        // If digit push in stack
        else if (isdigit(exp[i]))
        {
            int num = 0;
            // extract full number
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            push(stack, num);
        }
        // If operator, pop 2 values and operate.
        else
        {
            int op1 = pop(stack);
            int op2 = pop(stack);

            switch (exp[i])
            {
            case '+':
                push(stack, op2 + op1);
                break;
            case '-':
                push(stack, op2 - op1);
                break;
            case '*':
                push(stack, op2 * op1);
                break;
            case '/':
                push(stack, op2 / op1);
                break;
            }
        }
    }
    // return last element
    return pop(stack);
}

// Driver program to test above functions
int main()
{
    char exp[] = "900 100 +";
    printf("%d", evaluatePostfix(exp));
    return 0;
}