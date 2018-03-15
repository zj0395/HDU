#include<iostream>
#include<cmath>
#include<cstring>
int gcd(int a, int b)
{
    return b==0 ? a:gcd(b, a%b);
}
using namespace std;
int main()
{
    char number[14];
    int num;
    cin>>num;
    while( num-- )
    {
        cin>>number;
        int pos = 0;
        int normal = 0;
        int i=2;
        for( ; i<strlen(number); ++i )
        {
            if( number[i] == '(')
                break;
            normal*=10;
            normal+=number[i]-'0';
            ++pos;
        }
        pos = pow(10, pos);
        if( i != strlen(number) )
        {
            int normal2=0, pos2=0;;
            for( ++i; i<strlen(number)-1; ++i )
            {
                normal2*=10;
                normal2+=number[i]-'0';
                ++pos2;
            }
            pos2=pow(10,pos2)-1;
            if( pos!=1 )
            {
                normal*=pos2;
                normal+=normal2;
                pos*=pos2;
            }
            else
            {
                pos=pos2;
                normal=normal2;
            }
        }
        int g = gcd(normal, pos);
        cout<<normal/g<<"/"<<pos/g<<"\n";
    }
    return 0;
}
