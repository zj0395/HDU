#include<iostream>
using namespace std;
int gcd(int num1, int num2)
{
    return num2==0? num1 : gcd(num2, num1%num2);
}
int main()
{
    int num;
    cin>>num;
    int m, n;
    while(num--)
    {
        cin>>m>>n;
        cout<<(gcd(m,n)==1?"NO\n":"YES\n");
    }
    return 0;
}
