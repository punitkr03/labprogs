// Program to implement Doubly-linked list.
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
        printf("%d  ", temp->data);
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
    displayLL();
    return head;
}

node *insertB(int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = head;
    head = new;
    new->prev = NULL;
    displayLL();
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
    displayLL();
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
    displayLL();
    return head;
}

node *deleteB()
{
    node *temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
    displayLL();
    return head;
}

node *deleteE()
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
    displayLL();
    return head;
}

node *deleteTarget(int target)
{
    node *temp = head;
    while (temp->data != target)
    {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    node *temp3 = temp->prev;
    temp3->next = temp2;
    temp2->prev = temp3;
    free(temp);
    displayLL();
    return head;
}

int main()
{
    head = createLL(4);
    head = insertB(5);
    head = insertE(6);
    head = deleteB();
    head = deleteE();
    head = insertAfter(7, 2);
    head = deleteTarget(7);
    return 0;
}