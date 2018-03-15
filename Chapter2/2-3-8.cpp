#include<iostream>
using namespace std;
#define SIZE 21
int main()
{
    long long a[SIZE][SIZE]={0};
    int i, j, m, n;
    for(i=0; i<SIZE; ++i)
        a[i][0]=1;
    for(i=1;i<SIZE;++i)
        for(j=1;j<i+1;++j)
            a[i][j]=a[i-1][j]+a[i][j-1];
    while(cin>>m>>n)
        cout<<a[m][n]<<"\n";
    return 0;
}
