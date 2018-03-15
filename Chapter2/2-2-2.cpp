#include<iostream>
using namespace std;
int solve(int num)
{
    for( int b=num+1; ;++b )
    {
        int cycleT=0;
        int live = 2*num;
        int count=0;
        int countNew=0;
        while( live>num )
        {
            countNew+=b;
            if( countNew%live==0 ? countNew>num : countNew%live>num )
            {
                cycleT=(countNew-1)/live-
                    (count-1)/live;
                --live;
                countNew-=cycleT;
                --countNew;
                countNew%=live;
            }
            else
                break;
            count=countNew;
        }
        if( live==num )
            return b;
    }
}
int main()
{
    int result[15] = {0};
    int num;
    while( cin>>num&&num )
    {
        if( result[num]==0 )
            result[num] = solve(num);
        cout<<result[num]<<"\n";
    }
    return 0;
}
