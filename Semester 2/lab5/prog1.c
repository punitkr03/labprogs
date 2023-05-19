// Program to implement Circular Linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} node;

node *head;

void display()
{
    node *temp;
    temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
        }
    }
    temp = temp->next;
    temp->next = head;
    display();
    return head;
}

node *insertB(int data)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    new->next = head;
    head = new;
    temp->next = head;
    display();
    return head;
}

node *insertE(int data)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = head;
    display();
    return head;
}

node *deleteB()
{
    node *ptr = head;
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(ptr);
    display();
    return head;
}

node *deleteE()
{
    node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    node *ptr = temp->next;
    temp->next = head;
    free(ptr);
    display();
    return head;
}

int main()
{
    head = createLL(4);
    head = insertB(5);
    head = insertE(6);
    head = deleteB();
    head = deleteE();
    return 0;
}