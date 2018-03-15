#include<iostream>
using namespace std;
int main()
{
    long long ret[50]={3,6,6};
    for(int i=3;i<50;++i)
        ret[i]=ret[i-1]+ret[i-2]*2;
    int m;
    while(cin>>m)
        cout<<ret[--m]<<"\n";
}
