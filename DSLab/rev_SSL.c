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
    newnode->next=NULL;
    return newnode;
}
struct node *insertatfront(struct node *head)
{
    struct node *newnode;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    newnode->next=head;
    head=newnode;
    return head;
}
void display(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
struct node *reverse(struct node *head)
{
    struct node *temp,*cur,*prev;
    if(head==NULL)
    {
        printf("List is empty\n");

    }
    else
    {
        prev=NULL;
        cur=temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        head=prev;
    }
    return head;

}
int main()
{
    struct node *head=NULL;
    int choice;
    while(1)
    {
        printf("1.Insert at front\n2.Display\n3.Reverse\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            head=insertatfront(head);
            break;

            case 2:
            display(head);
            break;

            case 3:
            head=reverse(head);
            break;

            case 4:
            exit(0);
        }
    }
   return 0;
}
