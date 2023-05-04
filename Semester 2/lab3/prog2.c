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

int pop(S *stack)
{
    return stack->array[stack->top--];
}

void push(S *stack, int op)
{
    stack->array[++stack->top] = op;
}

int evaluatePostfix(char *exp)
{
    S *stack = createStack(strlen(exp));
    int i;
    // Scan all characters one by one
    for (i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i] == ',')
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
    int val = pop(stack);
    if (stack->top == -1)
        return val;
    else
        return -1;
}

// Driver program to test above functions
int main()
{
    char exp[] = "2,8,-,4,+,5,6,7,*,+,*";
    if(evaluatePostfix(exp) == -1)
    printf("Invalid expression.\n");
    else
    printf("%d", evaluatePostfix(exp));
    return 0;
}