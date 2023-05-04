// Infix to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct Stack
{
	int top;
	int arr[MAX];
} S;
int precedence(char operator)
{
	switch (operator)
	{
	case '+':
	case '-':
		return 10;
	case '*':
	case '/':
		return 20;
	case '^':
		return 30;
	default:
		return -1;
	}
}

int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char *infix)
{
	int i, j;
	int len = strlen(infix);
	char *postfix = (char *)malloc(sizeof(char) * (len));

	S stack;
	stack.top = -1;

	for (i = 0, j = 0; i < len; i++)
	{
		// If the scanned character is operand add to postfix
		if (isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
		}

		// If ( is encountered push in stack
		else if (infix[i] == '(')
		{
			stack.arr[++stack.top] = infix[i];
		}

		// if the scanned character is ')' continuously pop until (
		else if (infix[i] == ')')
		{
			while ((stack.top) > -1 && stack.arr[stack.top] != '(')
				postfix[j++] = stack.arr[stack.top--];
			if ((stack.top) > -1 && stack.arr[stack.top] != '(')
				printf("Invalid Expression");
			else
				stack.top--;
		}

		// If the scanned character is an operator push in stack
		else if (isOperator(infix[i]))
		{
			while ((stack.top) > -1 && precedence(stack.arr[stack.top]) >= precedence(infix[i]))
				postfix[j++] = stack.arr[stack.top--];
			stack.arr[++stack.top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while ((stack.top) > -1)
	{
		if (stack.arr[stack.top] == '(')
			printf("Invalid Expression");
		postfix[j++] = stack.arr[stack.top--];
	}
	postfix[j] = '\0';
	printf("%s\n", postfix);
}

int main()
{
	char infix[MAX] = "a+b*c/d";

	infixToPostfix(infix);
	return 0;
}