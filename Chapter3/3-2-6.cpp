//动态规划，需自己设置排序条件和可以使用的条件
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define SIZE 30
struct Rect
{
    void set(int a, int b, int c)
    {
        x = a>b?a:b;
        y = a>b?b:a;
        h = c;
    }
    bool operator <(Rect&r)
    {
        return x<r.x && y<r.y;
    }
    int x;
    int y;
    int h;
};
int main()
{
    Rect rect[SIZE*3];
    int heightSum[SIZE*3];
    int n, x, y, h;
    int idx = 0;
    while( cin>>n && n )
    {
        int len = 0;
        for(int i=0; i<n; ++i)
        {
            cin>>x>>y>>h;
            if( x!=y )
            {
                rect[len++].set(x, h, y);
                rect[len++].set(y, h, x);
                if( h!=x && h!=x )
                    rect[len++].set(x, y, h);
            }
            else
            {
                rect[len++].set(x, h, y);
                if( h!=x )
                    rect[len++].set(x, y, h);
            }
        }
        sort(rect, rect+len, [](Rect&l, Rect&r)
                {
                    if( l.x==r.x )
                        if( l.y==r.y )
                            return l.h<r.h;
                        else
                            return l.y<r.y;
                    return l.x<r.x;
                });
        int maxHeight = 0;
        memset(heightSum, 0, sizeof(heightSum));
        for( int i=0; i<len; ++i )
        {
            int tmpHeight = 0;
            for(int j=0; j<i; ++j)
            {
                if( rect[j] < rect[i] )
                {
                    if( tmpHeight < heightSum[j] )
                        tmpHeight = heightSum[j];
                }
            }
            heightSum[i] = tmpHeight + rect[i].h;
            if( heightSum[i] > maxHeight )
                maxHeight = heightSum[i];
        }
        cout<<"Case "<<++idx<<": maximum height = "<<maxHeight<<"\n";
    }
    return 0;
}
