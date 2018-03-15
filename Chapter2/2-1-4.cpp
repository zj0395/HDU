#include<iostream>
using namespace std;
int gcd(int num1, int num2)
{
    return num2==0? num1 : gcd(num2, num1%num2);
}
int main()
{
    int num;
    cin>>num;
    int a, b;
    while( num-- )
    {
        cin>>a>>b;
        int d;
        for( int c=2; (d=c*b)<a; ++c )
        {
            if( b==gcd(a, d) )
            {
                cout<<d<<"\n";
                break;
            }
        }
    }
    return 0;
}
