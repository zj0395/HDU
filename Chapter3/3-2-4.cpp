//动态规划，质量 w 递增为第一条件，速度 s 递减为第二条件
#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 1000
struct Mouse
{
    int w;
    int s;
    int no;
    bool operator <(Mouse&right)
    {
        return w < right.w && s > right.s;
    }
};
struct Node
{
    Node():pre(-1),num(0){}
    int pre;
    int num;
};
int main()
{
    Mouse mice[SIZE];
    Node  nodes[SIZE];
    int len=0;
    int maxNum = 0, maxIdx = 0;
    while( cin>>mice[len].w>>mice[len].s )
    {
        mice[len].no = len+1;
        ++len;
    }
    sort( mice, mice+len, [](Mouse&l, Mouse&r)
            {
                if(l.w == r.w)
                    return l.s>r.s;
                return l.w<r.w;
            });
    for(int i=0; i<len; ++i )
    {
        int tmpNum = 0;
        for( int j=0; j<i; ++j )
        {
            if( mice[j] < mice[i] )
            {
                if( tmpNum < nodes[j].num )
                {
                    tmpNum = nodes[j].num;
                    nodes[i].pre = j;
                }
            }
        }
        nodes[i].num = 1 + tmpNum;
        if( nodes[i].num > maxNum )
        {
            maxNum = nodes[i].num;
            maxIdx = i;
        }
    }
    cout<<maxNum<<"\n";
    int idx = maxIdx;
    int result[SIZE];
    for(int i=0; i<maxNum; ++i)
    {
        result[i] = mice[idx].no;
        idx = nodes[idx].pre;
    }
    while( maxNum-- )
        cout<<result[maxNum]<<"\n";
    return 0;
}
