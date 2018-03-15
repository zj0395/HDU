#include<iostream>
using namespace std;
#define SIZE 40
int main()
{
    int ret[SIZE]={1,2};
    for(int i=2; i<SIZE; ++i)
    {
        ret[i] = ret[i-1] + ret[i-2];
    }
    int m, n;
    cin>>m;
    while( m-- )
    {
        cin>>n;
        cout<<ret[n-2]<<"\n";
    }
    return 0;
}
