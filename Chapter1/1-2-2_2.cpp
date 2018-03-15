#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void getOnly( vector<int>& vec )
{
    if( vec.size() <2 )
        return;
    std::sort( vec.begin(), vec.end()  );
    int dest = vec[0];
    for( int i=1; i<vec.size(); ++i )
    {
        if( dest != vec[i]  )
            break;
        else
            dest = vec[++i];
    }
    cout << dest <<endl;
}

int main()
{
    string str;
    istringstream is;
    while( getline(cin, str) && !str.empty()  )
    {
        is.clear();
        is.str(str);
        vector<int> vec;
        int tmp;
        while( is>>tmp  )
            vec.push_back(tmp);
        getOnly( vec );
    }
    return 0;
}
