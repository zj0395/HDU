//动态规划，最长公共子序列
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1200
int main()
{
    char a[SIZE],b[SIZE];
    int aLen, bLen;
    int ret[SIZE][SIZE];
    while( cin>>a>>b )
    {
        aLen = strlen(a);
        bLen = strlen(b);
        memset(ret, 0, sizeof(ret));
        for( int i=1; i<=aLen; ++i )
        {
            for(int j=1; j<=bLen; ++j)
            {
                if( a[i-1]==b[j-1] )
                    ret[i][j] = ret[i-1][j-1]+1;
                else
                    ret[i][j] = max(ret[i-1][j], ret[i][j-1]);
            }
        }
        cout<<ret[aLen][bLen]<<"\n";
    }
    return 0;
}
