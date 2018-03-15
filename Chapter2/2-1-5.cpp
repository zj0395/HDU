#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int num;
    bool fri[32769];
    cin>>num;
    while( num-- )
    {
        int N, friNum=0;
        cin>>N;
        memset( fri, 0, sizeof(bool)*N );
        for( int i=2; i<=N/2; ++i )
        {
            if( N % i ==0 )
            {
                for( int j=i; j<N; j+=i )
                    fri[j]=1;
            }
        }
        for( int i=0; i<N; ++i )
            if( fri[i] )++friNum;
        cout<<N-1-friNum<<"\n";
    }
    return 0;
}
