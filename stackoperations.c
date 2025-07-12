#include <stdio.h>
#define MAX 100
void push();
int pop();
int peek();
void display();
int search();
int stack[MAX];
int top = -1;

int main()
{
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

void push()
{
    int ele;
    printf("Enter element to push: ");
    scanf("%d", &ele);

    if (top == MAX - 1)
	 {
        printf("Stack Overflow\n");
    }
	 else
	  {
        stack[++top] = ele;
        printf("Element %d pushed to stack\n", ele);
    }
}

int pop()
{
    if (top == -1)
	{
        printf("Stack Underflow\n");
        return -1;
    }
	 else
	  {
        return stack[top--];
    }
}

int peek()
{
    if (top == -1)
	{
        printf("Stack is empty\n");
        return -1;
    } else
	 {
        return stack[top];
    }
}

void display()
 {
    if (top == -1)
	 {
        printf("Stack is empty\n");
    }
	else
	{
        printf("Stack elements:\n");
        for (int i = 0; i <= top; i++)
		 {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int search()
{
    int ele;
    printf("Enter element to search: ");
    scanf("%d", &ele);

    for (int i = 0; i <= top; i++)
	 {
        if (stack[i] == ele)
		{
            printf("Element %d found at position %d (0-indexed).\n", ele, i);
            return i;
        }
    }
    printf("Element %d not found in the stack.\n", ele);
    return -1;
}
