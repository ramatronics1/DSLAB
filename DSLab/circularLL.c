#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode;
    return newnode;
}

struct node *insertatend(struct node *head)
{
    struct node *temp,*newnode;
    if(head==NULL)
    {
         newnode=create();
        head=newnode;
        head->next=newnode;
        return head;
    }
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
     newnode=create();
    temp->next=newnode;
    newnode->next=head;
    return head;
}

struct node *insertatfront(struct node *head)
{
    struct node *newnode,*temp;

    if(head==NULL)
    {
         newnode=create();
        head=newnode;
        head->next=newnode;
        return head;
    }
     newnode=create();
    newnode->next=head;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
      head=newnode;
    temp->next=head;
    return head;
}

struct node *deleteatfront(struct node *head)
{
    struct node *temp,*p;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->next==head)
    {
        free(head);
        return NULL;
    }
    p=temp=head;
    while(temp->next!=head)
    {
       temp=temp->next;
    }
    head=head->next;
    temp->next=head;
    free(p);
    return head;
}

struct node *deleteatend(struct node *head)
{
    struct node *newnode,*temp,*p;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->next==head)
    {
        free(head);
        return NULL;
    }
    temp=head;
    while(temp->next!=head)
    {
        p=temp;
        temp=temp->next;
    }
    p->next=head;
    free(temp);
    return head;

}
void display(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}
int main()
{
    struct node *head=NULL;
    int choice;
    while(1)
    {
       printf("1.Insert at end\n2.Insert at front\n3.Display\n4.Delete at end\n5.Delete at front\n");
       printf("Enter the choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           head=insertatend(head);
           break;

           case 2:
           head=insertatfront(head);
           break;

           case 3:
           display(head);
           break;

           case 4:
           head=deleteatend(head);
           break;

           case 5:
           head=deleteatfront(head);
           break;

           default :
           exit(0);
       }
    }
    return 0;
}
