#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
typedef double T;
typedef function< T(T) > Func;
T getResult( T a, T b, T c, T begin, T end )
{
    T ret[2] = {begin, end};
    for( int i=0; i<2; ++i )
    {
        ret[i] = a/3*pow(ret[i],3) + b/2*pow(ret[i],2) + c*ret[i];
    }
    return ret[1]-ret[0];
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    int num;
    cin>>num;
    while( num-- )
    {
        T x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        T b1, c1;
        T a2, b2, c2;
        b1 = (y3-y2)/(x3-x2);
        c1 = y2-b1*x2;
        a2 = ((y3-y2)/(x3-x2)-(y2-y1)/(x2-x1))/(x3-x1);
        b2 = (y2-y1)/(x2-x1)-a2*(x2+x1);
        c2 = y1-a2*x1*x1-b2*x1;
        cout<<getResult( a2, b2-b1, c2-c1, x2, x3 )<<"\n";
    }
    return 0;
}
