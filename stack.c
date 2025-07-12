#include<stdio.h>
void push (int ele);
int pop();
int peek();
void display();
int stack[10];
int top = -1;
void main();
{

}
void push (int ele)
{
    if (top==9)
    {
        printf("The Stack is Overflow");
    }
    else
    {
        top++;
        stack[top]=ele;
        printf("The Element is Successfully Pushed\n");
    }
}
int pop()
{
    if(top==-1)
    {
        printf("The stack is Underflow");
        return;
    }
    else
    {
        int e=stack[top];
        top--;
        return e;
    }
}
int peek()
{
    if (top==-1)
    {
        printf("The Stack is Underflow\n");
        return;
    }
    else
    {
        return stack[top];
    }
}
void display()
{
    if (top=-1)
    {
        printf("The stack is Underflow\n");
    }
    else
    {
        int i;
        for(i=top;i>-1;i--)
        {
            printf("%d",stack [i]);
        }
    }
}
