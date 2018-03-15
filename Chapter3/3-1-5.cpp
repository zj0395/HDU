#include<iostream>
using namespace std;
int main()
{
    long long ret[10000]={2,7};
    for(int i=2;i<10000;++i)
        ret[i]=ret[i-1]+i*4+1;
    int m,x;
    cin>>m;
    while(m--)
    {
        cin>>x;
        cout<<ret[x-1]<<"\n";
    }
    return 0;
}
