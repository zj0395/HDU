#include<iostream>
using namespace std;
#define SIZE 41
int main()
{
    int N[SIZE]={1};
    for(int i=1;i<SIZE;++i)
    {
        N[i]=(N[i-1]*i)%2009;
    }
    int num;
    while( cin>>num )
    {
        if(num>=SIZE)
            cout<<"0"<<endl;
        else
            cout<<N[num]<<"\n";
    }
    return 0;
}
