//动态规划，从底至尾；官方提示 cin 可能会超时
#include<cstdio>
#include<cstring>
int max(int a, int b)
{
    return a>b?a:b;
}
using namespace std;
#define SIZE 100002
int main()
{
    int n, t, x;
    int ret[SIZE][12];
    while( scanf("%d", &n)!=EOF && n )
    {
        int maxT = 0;
        memset(ret, 0, sizeof(ret));
        while( n-- )
        {
            scanf("%d%d", &x, &t);
            ++ret[t][x];
            if( maxT < t )maxT=t;
        }
        for(int i=maxT-1; i>=0; --i)
        {
            ret[i][0] += max(ret[i+1][0], ret[i+1][1]);
            for(int j=1; j<10; ++j)
                ret[i][j] += max( ret[i+1][j-1], max(ret[i+1][j], ret[i+1][j+1]) );
            ret[i][10] += max(ret[i+1][10], ret[i+1][9]);
        }
        printf("%d\n", ret[0][5]);
    }
    return 0;
}
