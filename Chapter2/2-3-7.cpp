#include<iostream>
using namespace std;
const int SYSTEM=10000;//进制
const int SIZE=100;
class BigNum
{
public:
    BigNum(){cur=num+SIZE;len=0;}
    int *cur;
    int len;
    void operator =(int n)
    {
        len=SIZE;
        while(n)
        {
            num[--len]=n%SYSTEM;
            n/=SYSTEM;
        }
        updateLen(SIZE-len);
    }
    void updateLen(int l){len=l;cur=num+(SIZE-l);}
    friend ostream& operator << (ostream&out, BigNum&a)
    {
        for(int i=0;i<a.len;++i)
        {
            if( i )
            {
                out.width(4);
                out.fill('0');
            }
            out<<a.cur[i];
        }
        return out;
    }
private:
    int num[SIZE];
};
void multi(BigNum&left, int right, BigNum&result)
{
    int opt=0;
    int *l=left.cur;
    int lId=left.len;
    int *ret=result.cur+result.len-SIZE;
    int retId=SIZE;
    while(lId)
    {
        opt+= l[--lId] *right;
        ret[--retId] = opt%SYSTEM;
        opt /= SYSTEM;
    }
    while( opt )
    {
        ret[--retId] = opt % SYSTEM;
        opt /= SYSTEM;
    }
    result.updateLen(SIZE-retId);
}
void divide(BigNum&left, int right, BigNum&result)
{
    int opt=0;
    int *l=left.cur;
    int lId=left.len;
    int *ret=result.cur+result.len-lId;
    for(int i=0;i<lId;++i)
    {
        opt = opt*SYSTEM + l[i];
        ret[i] = opt / right;
        opt %= right;
    }
    int i=0;
    for(;i<lId;++i)
        if(ret[i])
            break;
    result.updateLen(lId-i);
}
const int LEN=103;
int main()
{
    int num;
    BigNum big[LEN];
    big[0]=1;
    big[1]=1;
    for(int i=2;i<LEN;++i)
    {
        multi( big[i-1], 4*i-2, big[i] );
        divide( big[i], i+1, big[i] );
    }
    while( cin>>num && num!=-1 )
    {
        cout<<big[num]<<"\n";
    }
    return 0;
}
