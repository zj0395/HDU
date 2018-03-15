#include<iostream>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);
int getResult(int n)
{
    return ceil((log(n)*n-n+0.5*log(2.0*n*PI))/log(10));
}
int main()
{
    int num;
    cin>>num;
    while(num--)
    {
        int n;
        cin>>n;
        cout<<getResult(n)<<"\n";
    }
    return 0;
}
