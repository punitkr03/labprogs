// Program to implement Singly-linked list
//and perform creation, insertion, deletion and traversal.
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int data ; 
    struct NODE * next;
}node; 


node * createLL(int n)
{
    int i =0 ; 
    node * head =NULL;
    node * temp = NULL;
    node * p = NULL;
    for(i =0 ; i<n ; i++)
    {
        temp =(node*)malloc(sizeof(node));
        printf("Enter data in node.\n");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        
        if (head == NULL)
        {
            head =temp ; 
        }
        else 
        {
            p=head;
            while(p->next !=NULL)
            p=p->next;
            p->next=temp;

        }

    }
    return head;
}

node* insertB(node *head, int data) {
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = head;
    head = new;
    return head;
}

node* insertE(node *head, int data) {
    node *new = malloc(sizeof(node));
    new->data = data;
    node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
    return head;
    
}

node* insertBetween(node *head, int data, int target) {
    node *new = malloc(sizeof(node));
    int flag = 1;
    new->data = data;
    node *temp = head;
    while(temp->data != target) {
        temp = temp->next;
        flag = -1;
    }
    if (flag == 1) {
        printf("Target not found!\n");
        exit(EXIT_SUCCESS);
    }
    node *temp2 = temp->next;
    temp->next = new;
    new->next = temp2;
    return head;
    
}

node* deleteB(node* head) {
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

node* deleteE(node* head) {
    node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    node* temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
    return head;
}

node* deleteBetween(node* head, int target) {
    node* temp = head;
    while(temp->data != target) {
        temp = temp->next;
    }
    node* temp2 = temp->next->next;
    node* temp3 = temp->next;
    temp->next = temp2;
    free(temp3);
    return head;
}

void displayLL(node * head)
{
    node * p =head ; 
    while (p!=NULL)
    {
        printf("-> %d  ", p->data);
        p=p->next;

    }
    printf("\n");
}


int main()
{
    int n=0 ; 
    node * head =NULL;
    printf("Enter no of nodes in the Linked List. \n");
    scanf("%d",&n);
    head =createLL(n);
    printf("Linked list before delete between.\n");
    displayLL(head);   
    head = deleteBetween(head, 2);
    printf("Linked List after deletion.\n");
    displayLL(head);   
    return 0;
}