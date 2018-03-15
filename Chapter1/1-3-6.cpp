#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct Student
{
    bool operator > (Student& right)
    {
        if( rightNum > right.rightNum )
            return true;
        if( rightNum < right.rightNum )
            return false;
        if( time == right.time )
            return strcmp( name, right.name ) < 0;
        return time < right.time;
    }
    char name[11];
    int rightNum;
    int time;
};
int main()
{
    int stuNum=0, grade, proNum;
    cin>>proNum>>grade;
    Student stuTmp;
    vector<Student> vec;
    while( cin>>stuTmp.name )
    {
        int tmp, rightNum=0, time=0;
        for( int i=0; i<proNum; ++i )
        {
            cin>>tmp;
            if( tmp>0 )
            {
                ++rightNum;
                time += tmp;
                if( getchar() == '(')
                {
                    cin>>tmp;
                    time += grade*tmp;
                    getchar();
                }
            }
        }
        stuTmp.time = time;
        stuTmp.rightNum = rightNum;
        vec.push_back( stuTmp );
    }
    sort( vec.begin(), vec.end(), [](Student&left, Student&right)
            {
                return left > right;
            });
    for( int i=0; i<vec.size(); ++i )
    {
        cout.width(10);
        cout.setf(ios::left);
        cout<<vec[i].name<<" ";
        cout.unsetf(ios::left);
        cout.width(2);
        cout<<vec[i].rightNum<<" ";
        cout.width(4);
        cout<<vec[i].time<<endl;
    }
    return 0;
}
