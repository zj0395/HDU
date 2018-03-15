#include<stdio.h>
int main()
{
    int n,i,x,y;
    while(scanf("%d",&n)!=EOF&&n)
    {
           x=0;
           while(n--)
           {
                scanf("%d",&y);
                x^=y;
           }
           printf("%d\n",x);
    }
    return 0;
}
