// 求解方程式
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double getResult(double x)
{
    return 8*pow(x, 4)+7*pow(x, 3)+2*pow(x, 2)+3*x+6;
}
int main()
{
    int n;
    cin >> n;
    int number;
    cout.setf(ios::fixed);
    while( n-- )
    {
        cin >> number;
        double b=0, e=100;
        double nTry;
        double r;
        if( number < getResult(0) || number > getResult(e)  )
        {
            cout<<"No solution!\n";
            continue;
        }
        // 精度
        while( abs(e-b)>1e-8  )
        {
            nTry = (b+e)/2;
            r = getResult(nTry);
            if( r>number  )
                e = nTry;
            else if( r<number )
                b = nTry;
            else
                break;
        }
        cout<<setprecision(4)<<nTry<<"\n";
    }
    return 0;
}
