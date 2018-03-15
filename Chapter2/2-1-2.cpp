#include<iostream>
#include<cmath>
using namespace std;
bool judge(int n)
{
    if( n<4 )
        return true;
    for( int i=2; i<=sqrt(n); ++i )
    {
        if( n%i==0 )
            return false;
    }
    return true;
}
int main()
{
    int num;
    while( cin>>num )
    {
        int  ret=0, tmp;
        for(int i=0;i<num;++i)
        {
            cin>>tmp;
            if( judge(tmp) )++ret;
        }
        cout<<ret<<"\n";
    }
    return 0;
}
