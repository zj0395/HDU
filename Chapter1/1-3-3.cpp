#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char name[22];
    int grade;
};

int main()
{
    Student stu[1000];
    int proGrade[10];
    int stuNum, proNum, passGrade;
    while( cin>>stuNum && stuNum )
    {
        int passNum;
        cin >>proNum>>passGrade;
        for( int i=0; i<proNum; ++i  )
            cin>>proGrade[i];
        for( int i=0; i<stuNum; ++i  )
        {
            int allGrade = 0, gradeTmp;
            cin>>stu[i].name>>passNum;
            for( int p=0; p<passNum; ++p  )
            {
                cin>>gradeTmp;
                allGrade += proGrade[ gradeTmp-1 ];
            }
            stu[i].grade = allGrade;
        }
        sort( stu, stu+stuNum, [](Student&left, Student& right)->bool
                {
                    if( left.grade > right.grade )
                        return true;
                    else if( left.grade < right.grade )
                        return false;
                    else
                        return strcmp(left.name, right.name) < 0;
                });
        int passStuNum = 0;
        for( int i=0; i<stuNum; ++i  )
        {
            if( stu[i].grade >= passGrade )
                ++passStuNum;
        }
        cout<<passStuNum<<"\n";
        for( int i=0; i<passStuNum; ++i  )
        {
            cout<<stu[i].name<<" "<<stu[i].grade<<"\n";
        }
    }
    return 0;
}
