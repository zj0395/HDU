#include<iostream>
using namespace std;
int main()
{
    long long ret[55] = {1,2,3};
    for(int i=3;i<55;++i)
        ret[i]=ret[i-1]+ret[i-3];
    int m;
    while(cin>>m && m)
    {
        cout<<ret[m-1]<<"\n";
    }
    return 0;
}
