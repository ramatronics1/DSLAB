#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

struct node *insertatfront(struct node *head)
{
    struct node *NODE;
    NODE=create();
    if(head==NULL)
    {
        head=NODE;
        return head;
    }
    else
    {
        NODE->next=head;
        NODE->prev=NULL;
        head->prev=NODE;
        head=NODE;
        return head;
    }
}

void largest(struct node *head)
{
    struct node *temp,*max;
    temp=max=head;
    while(temp!=NULL)
    {
        if(temp->data > max->data)
        {
            max=temp;
        }
        temp=temp->next;
    }
    printf("the largest element is %d",max->data);
}

int main()
{
    struct node *head=NULL;
    int choice;
    while(1)
    {
        printf("\n1.insert\n2.largestelement\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=insertatfront(head);
                   break;

            case 2:largest(head);
                   break;
        }
    }
}
