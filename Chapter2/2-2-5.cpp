#include<iostream>
using namespace std;
int main()
{
    int num;
    int ret[10001]={0,2};
    for(int i=2;i<10001;++i)
    {
        ret[i]=ret[i-1]+6*(i-1);
    }
    cin>>num;
    while(num--)
    {
        int N;
        cin>>N;
        cout<<ret[N]<<"\n";
    }
    return 0;
}
