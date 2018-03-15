#include<iostream>
using namespace std;
#define SIZE 50
int main()
{
    long long ret[SIZE] = {1, 2};
    for(int i=2; i<SIZE; ++i)
        ret[i] = ret[i-1] + ret[i-2];
    int m, x, y;
    cin>>m;
    while( m-- )
    {
        cin>>x>>y;
        cout<<ret[y-x-1]<<"\n";
    }
    return 0;
}
