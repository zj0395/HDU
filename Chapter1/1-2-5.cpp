#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#define ASCIISIZE 256

int* buildMap()
{
    int * asciiMap = new int[ ASCIISIZE ];
    for( int i=0; i<ASCIISIZE; ++i  )
        asciiMap[i] = -1;
    const char* vowel = "ABCDF";
    const int vowelTransform[] = {4,3,2,1,0};
    for( int i=0; i<5; ++i )
        asciiMap[ vowel[i] ] = vowelTransform[i];
    return asciiMap;
}
int getPoint( char A  )
{
    static int* asciiMap = buildMap();
    return asciiMap[A];
}

double transform( vector<char> & str )
{
    int sum = 0;
    for( int i=0; i<str.size(); ++i  )
    {
        int one = getPoint(str[i]);
        if( one == -1  )
            return -1;
        sum += one;
    }
    return 1.0*sum/str.size();
}

int main()
{
    cout.setf(ios::showpoint); //将小数精度后面的0显示出来
    cout.precision(3); //设置输出精度，保留有效数字
    string s;
    istringstream is;
    while(getline(cin, s))
    {
        is.clear();
        is.str(s);
        vector<char> t;
        char tmp;
        while( is>>tmp  )
        {
            t.push_back(tmp);
        }
        double ret = transform(t);
        if( ret != -1  )
            cout<<ret<<"\n";
        else
            cout<<"Unknown letter grade in input\n";
    }
    return 0;
}
