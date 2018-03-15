//http://blog.csdn.net/u011721440/article/details/24516977
#include<iostream>
#include<cstring>
using namespace std;
#define LEN 1000
void multi(char* ret, char* num,char*out)
{
    static int number[LEN];
    memset(number, 0, sizeof(int)*LEN);
    int len1 = strlen(ret);
    int len2 = strlen(num);
    int len=len1+len2-1;
    for( int i=len2-1;i>=0;--i )
        for(int j=len1-1;j>=0;--j)
            number[len-i-j-1]+=(ret[j]-'0')*(num[i]-'0');
    int opt=0;
    ++len;
    for( int i=0;i<len;++i )
    {
        opt+=number[i];
        out[len-i-1]=opt%10+'0';
        opt/=10;
    }
    int i=0;
    for(;i<len;++i )
        if(out[i]!='0')
            break;
    int id=0;
    for(;i<len;++i)
        out[id++]=out[i];
    out[id]='\0';
}
void getChar(char*tmp,int i)
{
    tmp[0]=i/100+'0';
    tmp[1]=i%100/10+'0';
    tmp[2]=i%10+'0';
}
int main()
{
    char ret[LEN]="1";
    char tmp[4]="100";
    int m,n,i=0;
    while( cin>>m>>n , m||n )
    {
        cout<<"Test #"<<++i<<":\n";
        if(m<n)
        {
            cout<<"0\n";
            continue;
        }
        ret[0]='1';
        ret[1]='\0';
        for(int i=1;i<=m+n; ++i)
        {
            if(i!=m+1)
            {
                getChar(tmp, i);
                multi(ret, tmp, ret);
            }
        }
        getChar(tmp, m-n+1);
        multi(ret, tmp, ret);
        cout<<ret<<"\n";
    }
    return 0;
}
