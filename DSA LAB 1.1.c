#include <stdio.h>
#include <time.h>
#include <math.h>
int main()
{
    //clock_t a = clock();
    int n = 50;
    for(int i = 1;i <= n;i++){
        printf("%d\n",i);
    }
    //clock_t b = clock();
    //printf("exc %lf",(double)(b-a)/CLOCKS_PER_SEC);
}
