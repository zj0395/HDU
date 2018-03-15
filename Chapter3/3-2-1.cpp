//动态规划，最大相邻子序列的和
#include<iostream>
using namespace std;
int main()
{
    int m,n,num;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        cin>>n;
        int sum=0,max=-10000;
        int begin, end,tmpIdx=0;
        for(int j=0;j<n;++j)
        {
            cin>>num;
            sum+=num;
            if(sum>max)
            {
                max=sum;
                begin=tmpIdx;
                end=j;
            }
            if(sum<0)
            {
                sum=0;
                tmpIdx=j+1;
            }
        }
        cout<<"Case "<<1+i<<":\n";
        cout<<max<<" "<<1+begin<<" "<<1+end<<"\n";
        if(i!=m-1)
            cout<<"\n";
    }
    return 0;
}
