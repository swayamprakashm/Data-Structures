#include<stdio.h>
void infixtopostfix(char infix[20],char postfix[20]);
int precedence(char op);
void main()
{
    char infix[20],postfix[20];
    printf("Enter the infix expression");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("The postfix expression is %s",postfix);
}
void infixtopostfix(char infix[20],char postfix[20])
{
    char stack[20];
    char symbol;
    int i=0,j=0,top=-1;
    infix[i]!='\0';
    while(infix[i]!='\0')
    {
    symbol=infix[i];
    switch(symbol)
    {
    case'(':
    top++;
    stack[top]=symbol;
    break;
    case')':
    while(stack[top]!='(')
    postfix[j++]=stack[top--];
    top--;
    break;
    case'+':
    case'-':
    case'*':
    case'/':
    case'^':
    while(precedence(symbol)<=precedence(stack[top]&&top!=-1))
    {
        postfix[j++]=stack[top--];
    }
    stack[++top]=symbol;
    break;
    default:
        postfix[j++]=symbol;
        break;
    }
    i++;
    }
    while(top!=-1)
        postfix[j++]=stack[top--];
    postfix[j]='\0';
}
int precedence(char op)
{
    switch(op)
    {
    case'+':
    case'-':
    return 1;
    case'*':
    case'/':
    return 2;
    case'^':
    return 3;
    }
    return 0;
}
