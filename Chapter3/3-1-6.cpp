#include<iostream>
using namespace std;
int main()
{
    long long ret[30]={1,3};
    for(int i=2;i<30;++i)
        ret[i]=ret[i-1]+2*ret[i-2];
    int m,n;
    cin>>m;
    while(m--)
    {
        cin>>n;
        cout<<ret[--n]<<"\n";
    }
    return 0;
}
