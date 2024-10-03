#include <stdio.h>
int K,LB,UB,n, a[1000];
int main()
{
    scanf("%d",&n);
    for( K = 1; K <= n;K++)
    {
        scanf("%d",&a[K]);
    }
    scanf("%d %d",&LB, &UB);
    for(K = LB; K <= UB; K++)
    {
        printf("%d\n",a[K]);
    }
}
