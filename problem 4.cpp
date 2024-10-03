#include <stdio.h>
int j,LB = 1,K,n,x, a[1000];
int main()
{
    scanf("%d",&n);
    for( j = LB; j <= n;j++)
    {
        scanf("%d",&a[j]);
    }
    printf("Before Update:");
    for(j = LB; j <= n; j++)
    {
        printf(" %d",a[j]);
    }
    printf("\n");
    printf("Input location: ");
    scanf("%d",&K);
    printf("Input new value: ");
    scanf("%d",&x);
    a[K] = x;
    printf("After Update: ");
    for(j = LB; j <= n; j++)
    {
        printf(" %d",a[j]);
    }
    return 0;
}
/*
10
7 6 10 74 88 19 34 19 23 78
*/
