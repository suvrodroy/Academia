#include <stdio.h>
int j,LB = 1,K,n,x, a[1000];
int main()
{
    scanf("%d",&n);
    for( j = LB; j <= n;j++)
    {
        scanf("%d",&a[j]);
    }
    printf("Before Insertion:");
    for(j = LB; j <= n; j++)
    {
        printf(" %d",a[j]);
    }
    printf("\n");
    printf("Input location: ");
    scanf("%d",&K);
    printf("Input element: ");
    scanf("%d",&x);
    for(int j = n; j >= K; j--)
    {
        a[j+1] = a[j];
    }
    a[K] = x;
    n = n+1;
    printf("After Insertion: ");
    for(j = LB; j <= n; j++)
    {
        printf(" %d",a[j]);
    }
    return 0;
}
