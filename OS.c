#include<stdio.h>
#include<stdlib.h>
int main()
{
    int c=0;
    int i,at[5],bt[5],ct[5];
    int tat[5],wt[5];
    for(i=0;i<5;i++)
    scanf("%d",&at[i]);
    for(i=0;i<5;i++)
    scanf("%d",&bt[i]);
    int a,b;
    for(i=0;i<5;i++)
    {
        a=at[i];
        b=at[i+1];
        if(i==4)
        ct[i]=c+bt[i];
        if(a<b)
        {
            ct[i]=c+bt[i];
            c=ct[i];
        }
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(i=0;i<5;i++)
    printf("%d\n",ct[i]);
    return 0;
}