// 求函数最小值
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double F(double x, double y)
{
    return 42*pow(x, 6)+48*pow(x, 5)+21*pow(x, 2)+10*x-y;
}
// 求解函数
double getFResult(double b, double e, double y)
{
    double number = 0;
    double nTry;
    double r;
    if( number < F(0, y) || number > F(e, y)  )
    {
        return -1;
    }
    while( abs(e-b)>1e-8  )
    {
        nTry = (b+e)/2;
        r = F( nTry, y );
        if( r>number  )
            e = nTry;
        else if( r<number )
            b = nTry;
        else
            break;
    }
    return nTry;
}
// 函数结果
double F2( double x, double y  )
{
    return 6*pow(x, 7) + 8*pow(x,6) + 7*pow(x,3) + 5*pow(x,2) - y*x;
}
int main()
{
    int n;
    double y;
    cin >> n;
    cout.setf(ios::fixed);
    while( n-- )
    {
        cin >> y;
        double r = getFResult( 0, 100, y );
        cout<<setprecision(4)<<F2(r, y)<<endl;
    }
    return 0;
}
