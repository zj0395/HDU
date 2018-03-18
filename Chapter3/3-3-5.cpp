//动态规划，二维01背包
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 100
int main()
{
    int T;
    cin>>T;
    int M, N, L;
    int times[SIZE], values[SIZE];
    int ret[SIZE+1][1001];
    while( T-- )
    {
        memset( ret, 0, sizeof(ret) );
        cin>>N>>M>>L;
        for(int i=0; i<N; ++i)
            cin>>times[i]>>values[i];
        for(int i=0; i<=M; ++i)
        {
            for(int j=0; j<=L; ++j)
            {
                ret[i][j] = i==0? 0 : -99999;
            }
        }
        for(int i=0; i<N; ++i)
        {
            for(int j=M; j>=1; --j)
            {
                for(int k=L; k>=times[i]; --k)
                    ret[j][k] = max( ret[j][k], ret[j-1][k-times[i]]+values[i] );
            }
        }
        if( ret[M][L] < 0 )
            ret[M][L] = 0;
        cout<<ret[M][L]<<"\n";
    }
    return 0;
}
