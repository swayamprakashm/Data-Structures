#include <stdio.h>
#include <stdlib.h>

int main() 
{
int c=0;  
int i,at[5],bt[5],ct[5],tat[5],wt[5]; 
printf("Enter Arrival Times:\n");
for (i=0;i<5;i++)
scanf("%d",&at[i]);
printf("Enter Burst Times:\n");
for (i=0;i<5;i++)
scanf("%d", &bt[i]);
for (i=0;i<5;i++) 
{
if(c<at[i])  
c=at[i];
ct[i]=c+bt[i];
c=ct[i];  
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}   
printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
for (i=0;i<5;i++)
printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
return 0;
}