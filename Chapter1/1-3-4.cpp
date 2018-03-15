#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Time
{
    friend istream & operator>>(istream&in, Time&t)
    {
        int d, dayTime;
        cin>>d;
        cin.get();
        dayTime = d*3600;
        cin>>d;
        dayTime += d*60;
        cin.get();
        cin>>d;
        dayTime += d;
        t.dayTime = dayTime;
        return in;
    }
    int operator <(Time& right)
    {
        return dayTime < right.dayTime;
    }
    int operator >(Time& right)
    {
        return dayTime > right.dayTime;
    }
    int dayTime;
};

struct Recode
{
    friend istream & operator>>(istream&in, Recode& r)
    {
        in>>r.name>>r.inTime>>r.outTime;
        return in;
    }
    char name[16];
    Time inTime;
    Time outTime;
};

int main()
{
    vector<Recode> vec;
    int dayNum, recodeNum;
    cin>>dayNum;
    for( int i=0; i<dayNum; ++i  )
    {
        cin>>recodeNum;
        if( vec.size()<recodeNum )
            vec.resize(recodeNum);
        Recode* recode = &vec[0];
        for( int n=0; n<recodeNum; ++n  )
        {
            cin>>recode[n];
        }
        sort( recode, recode+recodeNum,
                [](Recode&left, Recode&right)
                {
                    return left.inTime < right.inTime;
                });
        cout<<recode[0].name<<" ";
        sort( recode, recode+recodeNum,
                [](Recode&left, Recode&right)
                {
                    return left.outTime > right.outTime;
                });
        cout<<recode[0].name<<"\n";
    }
    return 0;
}
