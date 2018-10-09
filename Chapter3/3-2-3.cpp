//动态规划，求最大递增子序列的和
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1001
int getResult(int*array, int len)
{
	int maxSum = 0;
    static int ret[SIZE];
    memset(ret, 0, sizeof(ret));
    for(int i=0; i<len; ++i)
    {
		int tmp = 0;
        for( int j=0; j<i; ++j )
        {
			if( array[j]<array[i] )
			{
				if( tmp<ret[j] )
					tmp = ret[j];
			}
        }
		ret[i] = array[i]+tmp;

		if( maxSum<ret[i] )
			maxSum = ret[i];
    }
	return maxSum;
}
int main()
{
    int num[SIZE];
    int m;
    while(cin>>m && m)
    {
        for(int i=0; i<m; ++i)
            cin>>num[i];
        cout<<getResult(num, m)<<"\n";
    }
    return 0;
}
