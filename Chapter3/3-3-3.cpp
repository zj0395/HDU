//先贪心算法，到临界点以后使用动态规划
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define SIZE 100001
#define BOUNDRY 30
struct Node
{
    int v, c;
    bool operator < (const Node& r)const
    {
        return v*1.0/c > r.v*1.0/r.c;
    }
};
int main()
{
    char ch[11];
    int N, C;
    Node nodes[SIZE];
    int ret[SIZE];
    while( (scanf("%d%d", &N, &C) )==2 )
    {
        memset(ret, 0, sizeof(ret));
        int vSum = 0, cSum = 0;
        for(int i=0; i<N; ++i)
        {
            scanf("%s%d%d", ch, &nodes[i].v, &nodes[i].c);
            vSum += nodes[i].v;
            cSum += nodes[i].c;
        }
        if( cSum <= C )
        {
            printf("%d\n", vSum);
            continue;
        }
        sort( nodes, nodes+N );
        int cur = 0, sum = 0;
        while( C > BOUNDRY )
        {
            sum += nodes[cur].v;
            C -= nodes[cur].c;
            ++cur;
        }
        for( int i=cur; i<N; ++i )
        {
            for( int j=C; j>=nodes[i].c; --j )
            {
                ret[j] = max(ret[j], ret[j-nodes[i].c]+nodes[i].v );
            }
        }
        printf("%d\n", ret[C]+sum);
    }
}
