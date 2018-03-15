#include<iostream>
#include<cstring>
using namespace std;
void cal(char* l, char*r, char*c,char*d, char*out)
{
    static char tmp[2555];
    int opt=0;
    int i=0;
    int m=strlen(l);
    int n=strlen(r);
    int cl=strlen(c);
    int dl=strlen(d);
    while(m||n||cl||dl)
    {
        opt+= (m>0?(l[--m]-'0'):0) + (n>0?(r[--n]-'0'):0)
            +(cl>0?(c[--cl]-'0'):0) + (dl>0?(d[--dl]-'0'):0);
        tmp[i++]=opt%10+'0';
        opt/=10;
    }
    if( opt  )
        tmp[i++]=opt%10+'0';
    int j=0;
    while(i)
        out[j++]=tmp[--i];
    out[j]='\0';
}
int main()
{
#define SIZE 7037
    typedef char* C;
    C *r=new C[SIZE];
    r[0]=new char[2];
    r[1]=new char[2];
    r[2]=new char[2];
    r[3]=new char[2];
    r[0][0]='1';r[0][1]='\0';
    r[1][0]='1';r[1][1]='\0';
    r[2][0]='1';r[2][1]='\0';
    r[3][0]='1';r[3][1]='\0';
    for(int i=4;i<SIZE;++i)
    {
        r[i]=new char[i/3+1];
        cal( r[i-4], r[i-3], r[i-2], r[i-1], r[i] );
    }
    int num;
    while(cin>>num)
        cout<<r[num-1]<<"\n";
    return 0;
}
