#include<stdio.h>
#include<stdlib.h>
struct node{
    char usn[100];
    char name[100];
    char branch[100];
    char sem[100];
    char phno[100];
    struct node *next;
};
struct node *create()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the USN :\n");
    scanf("%s",newnode->usn);
    printf("Enter name :\n");
    scanf("%s",newnode->name);
    printf("Enter the branch :\n");
    scanf("%s",newnode->branch);
    printf("Enter the sem :\n");
    scanf("%s",newnode->sem);
    printf("Enter the phone number :\n");
    scanf("%s",newnode->phno);
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
struct node *insertatend(struct node *head)
{
    struct node *newnode,*temp;

    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode=create();
    temp->next=newnode;
    return head;
}
struct node *deleteatend(struct node *head)
{
    struct node *newnode,*temp,*prev;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    temp=prev=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return head;

}
void display(struct node *head)
{
    struct node *temp;
    int i=1;
    temp=head;
    while(temp!=NULL)
    {

        printf("Details of person %d : \n",i);
        printf("USN : %s\n",temp->usn);
        printf("Name : %s\n",temp->name);
        printf("Branch : %s\n",temp->branch);
        printf("Sem : %s\n",temp->sem);
        printf("Phone number : %s\n",temp->phno);
        temp=temp->next;
        i++;
    }
}
void count(struct node *head)
{
    struct node *temp;
    int count=1;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
    }
    printf("The number of nodes is %d\n",count);
}
int main()
{
    struct node *head=NULL;
    int choice;
    int n,i;
    while(1)
    {
       printf("1.Insert at front\n2.Insert at end\n3.Display\n4.Dlete at end\n5.Count the number of nodes\n");
       printf("Enter the choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           printf("Enter the number of elements to be inserted\n");
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
           head=insertatfront(head);
           }
           break;

           case 2:
           head=insertatend(head);
           break;

           case 3:
           display(head);
           break;

           case 4:
           head=deleteatend(head);
           break;

           case 5:
           count(head);
           break;

           default :
           exit(0);
       }
    }
    return 0;
}
