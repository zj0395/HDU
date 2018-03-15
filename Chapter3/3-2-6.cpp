#include<iostream>
using namespace std;
#define SIZE 30
struct Rect
{
    int x;
    int y;
    int h;
};
int main()
{
    Rect rect[SIZE*2];
    int n, x, y, h, xTmp, yTmp, hTmp;
    while( cin>>n && n )
    {
        for(int i=0; i<n; ++i)
        {
            cin>>xTmp>>yTmp>>hTmp;
            h = xTmp>yTmp ? yTmp : xTmp;
            h = h>hTmp ? hTmp : h;
        }
    }
}
