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
void inorder(struct bst *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}
void preorder(struct bst *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(struct bst *root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}
int main()
{
    struct bst *root=NULL,*newnode;
    int choice,n,i;
    while(1)
    {
        printf("1.Insert new nodes\n2.BST Traversal\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the number of elements to be inserted\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
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
                printf("Inorder display\n");
                inorder(root);
                printf("\nPreorder display\n");
                preorder(root);
                printf("\nPostorder display\n");
                postorder(root);

            }
            break;

            default:
            exit(0);

        }
    }
    return 0;
}
