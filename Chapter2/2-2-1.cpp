#include<iostream>
#include<cmath>
using namespace std;
#define SIZE 21
int main()
{
    int fa[SIZE];
    fa[0]=0;fa[1]=1;
    for( int i=2; i<SIZE; ++i )
    {
        fa[i]=fa[i-2]+fa[i-1];
    }
    int num;
    while( cin>>num )
    {
        if( num<SIZE )
            cout<<fa[num]<<"\n";
        else
        {
            double k = -0.5*log10(5) + num*log10((1+sqrt(5*1.0))/2);
            k -= (int)k;
            double ans = pow(10,k);
            while(ans < 1000){
                ans *= 10;
            }
            cout << (int)ans <<"\n";
        }
    }
    return 0;
}
