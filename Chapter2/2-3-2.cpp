#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[630],b[630],c[660],i,j,k,l,m,n,cnt;
char s[10];
void pplus(int a[])
{
    int i,j,k,l;
    memset(c,0,sizeof(c));
    for(i=0;i<10;i++)//大数乘模板
    for(j=0;j<200;j++)
    c[i+j]+=b[j]*a[i];

    for(i=0;i<200;i++)
    {
        if(c[i]>=10)
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    for(i=0;i<300;i++)
    b[i]=c[i];
}
int main()
{
    while(scanf("%s%d",s,&n)!=EOF)
    {
        l=strlen(s);
        cnt=0;
        for(i=l-1;i>=0;i--)//判断小数点后有几位数
        if(s[i]=='.')
        cnt=l-1-i;
        int help=0;
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        int nmd=0;

        for(i=l-1;i>=0;i--)//先暂时消除输入数据的后置0
        if(s[i]!='0')
        break;

        if(s[i]=='.')//如果输入的类似1.   这样的数据
        nmd=1;
        for(i=l-1;i>=0;i--)//判断输入有无 小数点
        if(s[i]=='.')
        break;
        if(i==-1)
        nmd=1;

        b[0]=1;


        for(i=l-1;i>=0;i--) //储存数据
        if(s[i]>='0'&&s[i]<='9')
        a[help++]=s[i]-'0';


        for(i=0;i<n;i++) //递归相乘
        pplus(a);


        for(i=200;i>=cnt*n;i--)//输出
        if(b[i])
        break;
        for(i;i>=cnt*n;i--)
        printf("%d",b[i]);
        if(nmd==0) //如果结果是小数
        printf(".");
        int cnm=0;
        for(;i>=0;i--)
        {
            cnm=0;
            for(j=i;j>=0;j--)//消除后置0，其实可以直接输入成浮点型判断的
            {
                if(b[j])//但是我比较懒
                {
                    cnm=1;
                    break;
                }
            }
            if(cnm)
            printf("%d",b[i]);
        }
        printf("\n");
    }
}
