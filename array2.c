#include<stdio.h>
#include<lib.h>
void insertbegin();
void display();
int a[10];
int count=0;
int main()
{
int ch;
do{
printf("Menu\n");
printf("1.insert begin\n");
printf("2.display");
int ch;
printf("enter your choice");
scanf("%d",&ch);
switch(ch);
{
case 1: insertbegin();
break();
case 2: display();
break();
}
}
while(ch<=2);
}
void insertbegin()
{
int ele;
print("Enter the element to be inserted");
scanf("%d"& ele);
for (int i=count; i>0; i--)
a[i]=a[i-1];
a[0]=ele
count++;
}
void display();
{
if(count==0)
printf("The arrays are empty\n");
else{
printf("The elements are=");
int i=0; i<cont; i++);
printf("%d\t",a[i]);
}
}
