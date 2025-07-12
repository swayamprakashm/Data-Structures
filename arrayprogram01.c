#include <stdio.h>


void insertbegin();
void display();


int a[10];
int count = 0;

int main() {
    int ch;
    do {
        printf("Menu\n");
        printf("1. insert begin\n");
        printf("2. display\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch(ch) { 
            case 1:
                insertbegin();
                break;
            case 2:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (ch <= 2); 

    return 0;
}
void insertbegin() {
    int ele;
    printf("Enter the element to be inserted\n");
    scanf("%d", &ele);

    for (int i = count; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = ele;
    count++;
}
void display() {
    if (count == 0) {
        printf("The array is empty\n");
    } else {
        printf("The elements are: ");
        for (int i = 0; i < count; i++) 
            printf("%d\t", a[i]);
        printf("\n");
    }
}
