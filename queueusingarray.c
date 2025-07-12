//Queue using array
#include<stdio.h>
void insert(int ele);
void deleteele();
void display();
int front=-1,rear=-1;
int queue[10];
void main()
{
    int ch,ele;
    do{
        printf("\nMENU \n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        int ch,ele;
        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Enter the element to insert: ");
                scanf("%d", &ele);
                insert( ele);
        break;
        case 2:deleteele();
        break;
        case 3:display();
        break;
        case 4:printf("Exiting...\n");
        break;
        default:
            printf("Invalid choice, please enter a valid option");
        }
    }while(ch!=4);
}
void insert(int ele)
{
    if(rear==9)
    {
        printf("The QUEUE Is Overflow\n");
    }else{
if (front == -1)
 {
        front = 0;
        }
        rear++;
        queue[rear] = ele;
        printf("Element %d inserted\n", ele);
    }
}
void deleteele()
{
    if(front==-1||front>rear)
    {
        printf("Queue is Underflow\n");
    }else{
    printf("the element deleted is %d",queue[front]);
    front++;
    }
}
void display()
    { ui
    if (front == -1 || front > rear)
    {
        printf("\nQueue is underflow, not possible to print\n");
    } else {
        printf("\nThe Elements in Queue are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
