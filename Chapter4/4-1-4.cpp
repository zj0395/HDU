// 求梯形圆柱体的中的高
// http://acm.hdu.edu.cn/game/entry/problem/show.php?chapterid=4&sectionid=1&problemid=5
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI 3.141592653589793
#define PRECISION 1e-9
double F(double x, double R, double ratio)
{
    double u = R+ratio*x;
    return PI/3*x*(u*u+R*R+R*u);
}
// 求函数结果
double getFResult( double h, double R, double ratio, double number)
{
    double nTry;
    double r;
    double b = 0;
    double e = h;
    while( e-b>PRECISION  )
    {
        nTry = (b+e)/2;
        r = F( nTry, R, ratio );
        if( abs(r-number)<=PRECISION  )
            break;
        else if( r<number )
            b = nTry;
        else
            e = nTry;
    }
    return nTry;
}
// 函数结果
int main()
{
    int T;
    cin>>T;
    double r, R, H, V;
    cout.setf(ios::fixed);
    while(T--)
    {
        cin >> r>>R>>H>>V;
        // 写成 r-R, 后面getFResult(H, R ....) 就Wrong Answer
        double rRatio = (R-r)/H;
        cout<<setprecision(6)<<getFResult(H, r, rRatio, V )<<"\n";
    }
    return 0;
}
