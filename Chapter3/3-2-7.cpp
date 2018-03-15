//动态规划,依次递推
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 100
int main()
{
    int C, n;
    int num[SIZE][SIZE];
    int ret[SIZE];
    cin>>C;
    while(C--)
    {
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<i+1; ++j)
                cin>>num[i][j];
        }
        memcpy( ret, num[n-1], sizeof(int)*n );
        for( int i=n-2; i>=0; --i )
        {
            for( int j=0; j<i+1; ++j )
                ret[j] = num[i][j] + max(ret[j], ret[j+1]);
        }
        cout<<ret[0]<<"\n";
    }
    return 0;
}
