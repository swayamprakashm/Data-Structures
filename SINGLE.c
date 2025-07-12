#include<stdio.h>
#include<stdlib.h>
void insertbegin();
void display();
struct node
{
    int data;
    stuct node *next;
};
struct node *head=NULL;
void main()
{
    insertbegin();
    display();
    insertbegin();
    display();
}
void insert()
{

}
void display()
{
    if(head==NULL)
{
    printf("The SLL is Empty");
}
else
{
    sruct node *temp=head;
    while(temp!=NULL)
{
    printf("%d\t,temp->data");
    temp=temp->next;
}
}
}
