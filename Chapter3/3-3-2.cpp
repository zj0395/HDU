//动态规划，分组背包问题
#include<iostream>
#include<cstring>
using namespace std;
#define NUM 15
#define SIZE 10005
int main()
{
    int N, M, K;
    int ret[NUM][SIZE];
    int a[110], b[110], c[110];
    while( cin>>N>>M>>K )
    {
        memset(ret, 0, sizeof(ret));
        for(int i=0; i<N; ++i)
            cin>>a[i]>>b[i]>>c[i];
        for(int i=1; i<=K; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                for(int k=M; k>=1&&k>=b[j]; --k)
                {
                    if( a[j]==i )
                    {
                        ret[i][k] = max( max(ret[i][k], ret[i-1][k-b[j]]+c[j]),
                                        ret[i][k-b[j]]+c[j]);
                    }
                }
            }
        }
        if( ret[K][M] == 0 )
            cout<<"Impossible\n";
        else
            cout<<ret[K][M]<<"\n";
    }
    return 0;
}
