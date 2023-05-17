// Program to perform deletion in Doubly-linked list.
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

node *deleteB()
{
    node *temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
    displayLL(head);
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
    displayLL(head);
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
    displayLL(head);
    return head;
}

node *deleteBefore(int target)
{
    node *temp = head;
    while (temp->data != target)
    {
        temp = temp->next;
    }
    node *temp2 = temp->prev;
    node *temp3 = temp->prev->prev;
    temp3->next = temp;
    temp->prev = temp3;
    free(temp2);
    displayLL(head);
    return head;
}

node *deleteAfter(int target)
{
    node *temp = head;
    while (temp->data != target)
    {
        temp = temp->next;
    }
    temp = temp->next;
    node *temp2 = temp->next;
    node *temp3 = temp->prev;
    temp3->next = temp2;
    temp2->prev = temp3;
    free(temp);
    displayLL(head);
    return head;
}

int main()
{
    head = createLL(8);
    head = deleteB();
    head = deleteE();
    head = deleteTarget(5);
    head = deleteBefore(4);
    head = deleteAfter(4);
    return 0;
}