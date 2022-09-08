#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst *lchild;
    struct bst *rchild;
};

struct bst *create()
{
   struct bst *newnode;
   newnode=(struct bst *)malloc(sizeof(struct bst));
   printf("Enter the data\n");
   scanf("%d",&newnode->data);
   newnode->lchild=NULL;
   newnode->rchild=NULL;
   return newnode;
}

void insert(struct bst *root,struct bst *newnode)
{
    if(newnode->data < root->data)
    {
        if(root->lchild==NULL)
        {
            root->lchild=newnode;
        }
        else
        {
            insert(root->lchild,newnode);
        }

    }
    if(newnode->data >= root->data)
    {
        if(root->rchild==NULL)
        {
            root->rchild=newnode;
        }
        else
        {
            insert(root->rchild,newnode);
        }
    }
}

void search(struct bst *root)
{
    struct bst *temp;
    int key;
    int c=0;
    printf("Enter the key to be searched\n");
    scanf("%d",&key);
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==key)                  //note Anagha
        {
            printf("Key is present in the tree\n");
            c=1;
            return;
        }
        if(key<temp->data)
        {
            temp=temp->lchild;
        }
        else
        {
            temp=temp->rchild;
        }

    }
    if(c==0)
    {
        printf("The key is not present in the tree\n");
    }
}

int main()
{
    struct bst *root=NULL,*newnode;
    int choice,n,i;
    while(1)
    {
        printf("1.Insert number of nodes\n2.search\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the number of nodes whiich you want to insert\n");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                newnode=create();
                if(root==NULL)
                {
                    root=newnode;
                }
                else
                {
                    insert(root,newnode);
                }
            }
            break;

            case 2:
            if(root==NULL)
            {
                printf("Tree is not created\n");
            }
            else
            {
                search(root);
            }
            break;

        }
    }
    return 0;
}
