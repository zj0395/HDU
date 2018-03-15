#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 101
#define LEN  110
void add(char*l,char*r)//大数相加
{
    static char tmp[LEN];
    int m=strlen(l);
    int n=strlen(r);
    int opt=0;
    int i=0;
    while(m||n)
    {
        opt += (m>0?(l[--m]-'0'):0) + (n>0?(r[--n]-'0'):0);
        tmp[i++]=opt%10+'0';
        opt/=10;
    }
    if( opt )
        tmp[i++]=opt%10+'0';
    int j=0;
    while(i)
        l[j++]=tmp[--i];
    l[j]='\0';
}
void multi(char* ret, char* num,char*out)//大数相乘
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
        number[i]+=opt;
        opt=number[i]/10;
        number[i]%=10;
        out[len-i-1]=number[i]+'0';
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
int main()
{
    char ret[SIZE][LEN]={"1","1","2"};
    char tmp[LEN];
    for(int i=3;i<SIZE;++i)
    {
        for(int j=0;j<i;++j)
        {
            multi(ret[j],ret[i-j-1],tmp);
            add(ret[i], tmp);
        }
    }
    int num;
    while( cin>>num )
    {
        cout<<ret[num]<<"\n";
    }
    return 0;
}
