//未accept
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 8
#define RSIZE SIZE*26
void multi(char* ret, char* num)
{
    static int number[RSIZE];
    memset(number, 0, sizeof(int)*RSIZE);
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
        ret[len-i-1]=number[i]+'0';
    }
    int i=0;
    for(;i<len;++i )
        if(ret[i]!='0')
            break;
    int id=0;
    for(;i<len;++i)
        ret[id++]=ret[i];
    ret[id]='\0';
}
void getResult(char*num,int len,int pow)
{
    static char ret[RSIZE];
    int pointPos=0;
    for(;pointPos<len;++pointPos)
        if(num[pointPos]=='.')
            break;
    int first=0, last=len-1;
    for(;first<len;++first)
        if(num[first]!='0')
            break;
    for(;last>pointPos;--last)
        if(num[last]!='0')
            break;
    int afterPoint= last>pointPos ? last-pointPos:0;
    memcpy(ret, num+first, sizeof(int)*(pointPos-first));
    if( last>=pointPos )
    {
        memcpy(ret+pointPos-first, num+pointPos+1, sizeof(int)*(last-pointPos));
        --last;
    }
    ret[last+1]='\0';
    if(pow==1)
    {
        cout<<ret+first<<"\n";
        return;
    }
    memcpy(num, ret, sizeof(int)*(last-first+1));
    int small = first==pointPos;
    for(int i=1;i<pow;++i)
    {
        multi( ret, num );
    }
    if( afterPoint>0 )
    {
        int l=strlen(ret);
        if( small )
        {
            afterPoint*=pow;
            int offset = afterPoint-l+1;
            for(int i=l-1; i>=0; --i)
                ret[i+offset]=ret[i];
            for(int i=1;i<offset;++i)
                ret[i]='0';
            ret[0]='.';
            ret[1+afterPoint]='\0';
        }
        else
        {
            afterPoint*=pow;
            for(int i=0;i<afterPoint;++i)
                ret[l-i]=ret[l-i-1];
            ret[l-afterPoint]='.';
            ret[l+1]='\0';
        }
    }
    cout<<ret<<"\n";
}
int main()
{
    char real[SIZE];
    int pow;
    while( scanf("%s%d",real,&pow)!=EOF )
    {
        getResult(real, strlen(real), pow);
    }
    return 0;
}
