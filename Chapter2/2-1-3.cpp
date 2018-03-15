#include<iostream>
using namespace std;
int gcd(int num1, int num2)
{
    return num2==0? num1 : gcd(num2, num1%num2);
}
int lcm(int num1, int num2)
{
    return num1/gcd(num1, num2)*num2;
}
int main()
{
    int num;
    cin>>num;
    while( num-- )
    {
        int a, b, c, d;
        char tmp1, tmp2;
        cin>>a>>tmp1>>b>>c>>tmp2>>d;
        int k1 = gcd(a, b);
        a/=k1;
        b/=k1;
        int k2=gcd(c, d);
        c/=k2;
        d/=k2;
        int xx = lcm( a, c );
        int yy = gcd( b, d );
        if( xx % yy ==0 )
            cout<<xx<<"\n";
        else
            cout<<xx<<"/"<<yy<<"\n";
    }
    return 0;
}
