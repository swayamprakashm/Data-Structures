#include<stdio.h>
void insertbegin();
void insertend();
void insertpos();
void deletebegin();
void deleteend();
void deletepos();
void display();
int a[10];
int count=0;
int main()
{
	int ch;
do{
	printf("\nMenu \n1. insertbegin\n2. insertend\n3. insertpos\n4. deletebegin\n5. deleteend\n6. deletepos\n7. display\n8. exit\n");
	int ch;
	printf("Enter your choice =");
	scanf("%d",&ch);
	switch(ch)

   {
	case 1:insertbegin();
	break;
	case 2:insertend();
	break;
	case 3:insertpos();
	break;
	case 4:deletebegin();
	break;
	case 5:deleteend();
	break;
	case 6:deletepos();
	break;
	case 7:display();
	break;
}
}while(ch<=7);
}
void insertbegin()
{
	int ele;
	printf("Enter the element to be inserted =\n");
	scanf("%d",& ele);
	for(int i=count;i>0;i--)
	a[i]=a[i-1];
	a[0]=ele;
	count++;
}
void insertend()
{
	int ele;
	printf("Enter the element to be inserted =\n");
	scanf("%d",&ele);
	a[count]=ele;
	count++;
}
void insertpos()
{
	int ele,pos;
	printf("Enter the element to be inserted =\n");
	scanf("%d",&ele);
	printf("Enter the position to insert =\n");
	scanf("%d",&pos);
	if(pos<=count)
	{
		if(pos==count)
		a[pos]=ele;
		else
		{
			for(int i=count;i>pos;i--)
			a[i]=a[i-1];
			a[pos]=ele;
		}
		count++;
	}
	printf("Not possible to insert");
}
void deletebegin()
{
	if(count>0)
	{
		for(int i=0;i<count;i++)
		a[i]=a[i+1];
		count--;
		printf("the element is deleted from the begin\n");
	}
}
void deleteend()
{
	if(count>0)
	{
		count--;
		printf("The element is deleted from the end\n");
	}
}
void deletepos()
{
	int pos;
	printf("Enter the position to insert\n");
	scanf("%d",pos);
	if(count>0)
	{
		for(int i=pos;i<count;i++)
		a[i]=a[i+1];
		count--;
		printf("The Elements is deleted from the position\n");
	}
}
void display()
{
	if(count==0)
	printf("The array is empty\n");
	else
	{
		printf("The Element in the array are = ");
		for(int i=0;i<count;i++)
		printf("%d\t",a[i]);
	}
}
