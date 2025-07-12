#include<stdio.h>
#include<stdlib.h>
void push();
int pop();
int peek();
void display();
struct stack
{
    int data;
    struct stack*next;
};
struct stack*top=NULL;
int main(){
    int ch;
     do{

    printf("\nMenu \n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit \n");
    printf("Enter your choice = ");
    scanf("%d", &ch);
    int peekele;
    int rele;
    switch(ch)
{
        case 1:push();
        break;
        case 2:rele=pop();
        printf("\n Removed element is = ");
        break;
        case 3:peekele=peek();
        printf("The top element on stack is = %d",peekele);
        break;
        case 4:display();
        break;
        case 5:printf("Exit\n");
        break;
        default:printf("Invalid Choice\n");
        break;
}

}while(ch<=4);
    return 0;
}
void push(int ele)
{
    struct stack*newnode;
    newnode=(struct stack*)malloc(sizeof(struct stack));
    printf("Enter the element to be inserted = ");
    scanf("%d",&ele);
    newnode->data=ele;
    if(top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }else{
    newnode->next=top;
    top=newnode;
    printf("Element is pushed");
    }
}
int pop()
{
    int val;
    if(top==NULL)
    {
        printf("Stack is Underflow");
        return -1;
    }else{
    struct stack*temp=top;
    val=temp->data;
    top=top->next;
    temp->next=NULL;
    free(temp);
    return val;
    printf("Element is poped");
    }
}
int peek()
{
    if(top==NULL)
    {
        printf("Stack is Underflow");
        return -1;
    }else{
    return top->data;
    }
}
void display()
 {
    if (top == NULL)
    {
        printf("Stack is Underflow\n");
    } else {
    struct stack* temp = top;
    printf("\nThe elements in stack are = ");
    while (temp != NULL)
    {
    printf("%d\t", temp->data);
    temp = temp->next;
    }

    }
}
