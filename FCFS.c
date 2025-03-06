#include<stdio.h>
#include<conio.h>
#define MAX 10


void main()
{
    int n;
    int AT[MAX];
    int BT[MAX];
    int CT[MAX];
    int TAT[MAX];
    int WT[MAX];
    printf("Enter the number of processes :");
    scanf("%d",&n);
    printf("Enter Arrival Times :");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&AT[i]);
    }
    printf("Enter Burst Times :");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&BT[i]);
    }
    int flag = 0;
    for(int i = 0;i<n;i++)
    {
        if(AT[i] != 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+= BT[i];
            CT[i] = sum;
        }
        for(int i = 0;i<n;i++)
        {
            TAT[i] = CT[i] - AT[i];
        }
        for(int i = 0;i<n;i++)
        {
            WT[i] = TAT[i] - BT[i];
        }
    }
    else
    {

    }
    //
        printf("\n Arrival Times : ");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",AT[i]);
        }
        printf("\n Burst Times : ");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",BT[i]);
        }
        printf("\n Completion Times : ");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",CT[i]);
        }
        int tatsum =0;
        printf("\n Turn Around Times : ");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",TAT[i]);
            tatsum+= TAT[i];
        }
        int wtsum =0;
        printf("\n Waiting Times : ");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",WT[i]);
            wtsum+= WT[i];
        }
        printf("\n Average TAT : %lf",(double)((double)tatsum)/n);
        printf("\n Average WT : %lf",(double)((double)wtsum)/n);
    //

}
