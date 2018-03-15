#include<iostream>
using namespace std;
int getResult(int num)
{
    static int mod[20]={1,1,2,6,4,
        2,2,4,2,8,
        4,4,8,4,6,
        8,8,6,8,2};
    if( num<20 )
        return mod[num];
    int a20 = num/5;
    int ret=1;
    if( num>20 )
        ret=6;
    ret *= mod[num%20]*getResult(a20);
    return ret%10;
}
int main()
{
    int num;
    while(cin>>num)
    {
        cout<<getResult(num);
    }
    return 0;
}
