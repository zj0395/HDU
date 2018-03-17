//动态规划，求最大索引，而非最大结果
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 10001
int main()
{
    int T, N;
    double P;
    int Mj[SIZE];
    double Pj[SIZE];
    double ret[SIZE];
    cin>>T;
    while( T-- )
    {
        memset( ret, 0, sizeof(ret) );
        ret[0] = 1;
        cin>>P>>N;
        P = 1-P;
        int V = 0, idx=0;
        for( int i=0; i<N; ++i)
        {
            cin>>Mj[idx]>>Pj[idx];
            Pj[idx] = 1-Pj[idx];
            if( Pj[idx] >= P)
            {
                V += Mj[idx++];
            }
        }
        for( int i=0; i<idx; ++i )
        {
            for( int j=V; j>=Mj[i]; --j )
            {
                ret[j] = max( ret[j], ret[j-Mj[i]]*Pj[i] );
            }
        }
        for( int i=V; i>=0; --i )
        {
            if( ret[i] >= P )
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
}
