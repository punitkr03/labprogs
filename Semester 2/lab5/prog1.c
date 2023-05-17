// Program to perform insertion in Doubly-linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *prev;
    struct NODE *next;
} node;

node *head;

void displayLL()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node *createLL(int n)
{
    int i = 0;
    node *temp;
    for (i = 1; i <= n; i++)
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = i;
        new->prev = NULL;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new;
            new->prev = temp;
        }
    }
    displayLL(head);
    return head;
}

node *insertB(int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = head;
    head = new;
    new->prev = NULL;
    displayLL(head);
    return head;
}

node *insertE(int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
    new->prev = temp;
    displayLL(head);
    return head;
}

node *insertBetween(int data, int target)
{
    node *temp = head;
    node *new = malloc(sizeof(node));
    new->data = data;
    while (temp->data != target)
        temp = temp->next;
    node *temp2 = temp->next;
    temp->next = new;
    new->next = temp2;
    temp2->prev = new;
    new->prev = temp;
    displayLL(head);
    return head;
}

node *insertAfter(int data, int target)
{
    node *temp = head;
    node *new = malloc(sizeof(node));
    new->data = data;
    while (temp->data != target)
        temp = temp->next;
    node *temp2 = temp->next;
    temp->next = new;
    new->next = temp2;
    temp2->prev = new;
    new->prev = temp;
    displayLL(head);
    return head;
}

node *insertBefore(int data, int target)
{
    node *temp = head;
    node *new = malloc(sizeof(node));
    new->data = data;
    while (temp->next->data != target)
        temp = temp->next;
    node *temp2 = temp->next;
    temp->next = new;
    new->next = temp2;
    temp2->prev = new;
    new->prev = temp;
    displayLL(head);
    return head;
}

int main()
{
    head = createLL(3);
    head = insertB(4);
    head = insertE(5);
    head = insertBetween(6, 2);
    head = insertBefore(7, 1);
    head = insertAfter(8, 3);
    return 0;
}
