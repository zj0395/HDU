#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1100
int main()
{
    char input[SIZE];
    int  inNum[SIZE];
    int num;
    int len;
    int f[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
    while( cin>>input )
    {
        int ret=1;
        len = strlen(input);
        for(int i=0;i<len;++i)
            inNum[len-1-i]=input[i]-'0';
        while( len>1 )
        {
            while(inNum[len-1]==0)--len;
            ret*=f[inNum[1]%2*10+inNum[0]];
            ret%=10;
            int t=0;
            for(int i=len-1;i>=0;--i)
            {
                t=inNum[i]+t*10;
                inNum[i]=t/5;
                t%=5;
            }
        }
        cout<<ret*f[inNum[0]]%10<<"\n";
    }
}

