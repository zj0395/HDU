#include<iostream>
using namespace std;
const int SYSTEM=10000;//进制
const int SIZE=100;
class BigNum
{
public:
    BigNum():num{0}{cur=num+SIZE;len=0;}
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
void multi(BigNum&left, BigNum&right, BigNum&result)
{
    int lId=left.len;
    int rId=right.len;
    int *l=left.cur+lId-1;
    int *r=right.cur+rId-1;
    int *ret=result.cur+result.len-1;
    for(int i=0; i<lId; ++i)
    {
        for(int j=0; j<rId; ++j)
        {
            ret[-i-j] += l[-i]*r[-j];
        }
    }
    int opt=0;
    int retId=0;
    int len=rId+lId+1;
    for(; retId<len; ++retId)
    {
        opt += ret[-retId];
        ret[-retId]=opt%SYSTEM;
        opt /= SYSTEM;
    }
    while( ret[-retId+1]==0 )
        --retId;
    result.updateLen(retId);
    cout<<retId<<"\n";
}
void multi(BigNum&left, int right, BigNum&result)
{
    int *l=left.cur;
    int lId=left.len;
    int *ret=result.cur+result.len-SIZE;
    int retId=SIZE;
    int opt=0;
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
void test()
{
    BigNum t[3];
    t[0]=99999999;
    t[1]=99999999;
    multi(t[0], t[1], t[2]);
    cout<<t[2]<<"\n";
}
