#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node*right;
};
struct node *root=NULL;
struct node *insert(struct node *root, int val)
{
    struct node *newnode, *parentptr, *nodeptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if (root==NULL)
    {
        root=newnode;
    }else{
        parentptr=NULL;
        nodeptr=root;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            {
                nodeptr=nodeptr->left;
            }else{
            nodeptr=nodeptr->right;
            }
    }
    if(val<parentptr->data){
        parentptr->left=newnode;
    }else{
        parentptr->right=newnode;
    }
    }
    return root;
    }
    void postorder(struct node*root)
      {
          if(root!=NULL)
          {
              postorder(root->left);
              printf("%d\t",right->data);
              inorder(right->root);
          }
      }
      int main()
      {
          printf("Binary Search Tree: \n");
          root=insert(root, 15);
          root=insert(root, 20);
          root=insert(root, 69);
          root=insert(root, 8);
          root=insert(root, 36);
          printf("PostOrder Traversal is: \n");
          postorder(root);
      }
