// 01背包问题
// 对值进行一步处理
// http://acm.hdu.edu.cn/game/entry/problem/show.php?chapterid=3&sectionid=3&problemid=13
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#define MAX_NUM 10100
int main()
{
    int n, m;
    int ai[MAX_NUM];
    double bi[MAX_NUM];
    double DP[MAX_NUM];
    cout.setf(ios::fixed);
    while( cin>>n>>m && (n+m)  )
    {
        memset(DP, 0, sizeof(DP));
        for( int i=0; i<m; ++i  )
            cin>>ai[i]>>bi[i];
        for( int i=0; i<m; ++i )
            for( int j=n; j>=ai[i]; --j )
                DP[j] = max( DP[j], 1-(1-DP[j-ai[i]])*(1.0-bi[i]) );
        cout<<setprecision(1)<<DP[n]*100<<"%\n";
    }
    return 0;
}
