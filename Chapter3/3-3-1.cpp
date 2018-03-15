//动态规划,01背包问题
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1005
int main()
{
    int  ret[SIZE];
    int va[SIZE], vo[SIZE];
    int T, N, V;
    cin>>T;
    while(T--)
    {
        memset( ret, 0, sizeof(ret) );
        cin>>N>>V;
        for(int i=0; i<N; ++i)
            cin>>va[i];
        for(int i=0; i<N; ++i)
            cin>>vo[i];
        for( int i=0; i<N; ++i )
        {
            for( int j=V; j>=vo[i]; --j )
            {
                ret[j] = max(ret[j], ret[j-vo[i]]+va[i]);
            }
        }
        cout<<ret[V]<<"\n";
    }
    return 0;
}
