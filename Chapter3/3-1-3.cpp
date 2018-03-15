#include<iostream>
using namespace std;
#define SIZE 50
int main()
{
    long long ret[SIZE]={1,2,3};
    for(int i=3;i<SIZE;++i)
        ret[i]=ret[i-1]+ret[i-2];
    int m;
    while(cin>>m)
        cout<<ret[m-1]<<"\n";
    return 0;
}
