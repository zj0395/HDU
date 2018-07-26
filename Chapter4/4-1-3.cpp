// 寻找能否使等式满足
// 二分查找即可
// http://acm.hdu.edu.cn/game/entry/problem/show.php?chapterid=4&sectionid=1&problemid=4
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX1 501
#define MAX2 1001
int main()
{
    int l, n, m, s;
    int ln[MAX1], nn[MAX1], mn[MAX1];
    int tmp[MAX1*MAX1];
    int times = 1;
    while( cin>>l>>n>>m  )
    {
        for(int i=0; i<l; ++i)
            cin>>ln[i];
        for(int i=0; i<n; ++i)
            cin>>nn[i];
        for(int i=0; i<m; ++i)
            cin>>mn[i];
        cin >> s;
        std::sort(mn, mn+m);
        for(int i=0; i<l; ++i)
            for(int j=0; j<n; ++j)
                tmp[i*n+j] = ln[i]+nn[j];
        std::sort(tmp, tmp+l*n);
        int* end = std::unique(tmp, tmp+l*n);
        cout<<"Case "<<times++<<":\n";
        int numTmp;
        for(int i=0; i<s; ++i)
        {
            cin>>numTmp;
            bool f;
            for( int j=0; j<m; ++j  )
            {
                f = std::binary_search(tmp, end, numTmp-mn[j]);
                if( f )
                    break;
            }
            if(f)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
