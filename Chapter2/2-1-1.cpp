#include<iostream>
using namespace std;
int getDivi(int num1, int num2)
{
    int max = num1 > num2 ? num1 : num2;
    int min = num1 < num2 ? num1 : num2;
    while( max%min )
    {
        max = max % min;
        swap( max, min );
    }
    return min;
}
int getMulit(int num1, int num2)
{
    int maxDivisor = getDivi(num1, num2);
    return num1*num2/maxDivisor;
}
int main()
{
    int num1, num2;
    while( cin>>num1>>num2 )
    {
        cout<<getMulit(num1, num2)<<"\n";
    }
    return 0;
}
