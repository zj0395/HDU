#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void doCalculate(vector<vector<int> >& costs)
{
    for(int i=0; i<costs.size(); ++i)
    {
        vector<int> & oneLine = costs[i];
        int result = 0;
        for( int j=0; j<oneLine.size(); ++j )
        {
            result += oneLine[j];
        }
        cout<<result<<"\n";
        if( i != costs.size()-1  )
            cout<<"\n";
    }
}

int main()
{
    int N;
    int cost;
    vector<vector<int> > costs;
    string s;
    istringstream is;

    getline(cin, s);
    is.str(s);
    is>>N;
    for(int i =0 ; i < N; i++)
    {
        vector<int> t;
        getline(cin, s);
        is.clear();
        is.str(s);
        int num, tmp;
        is >> num;
        for( int numId=0; numId<num; ++numId  )
        {
            is >> tmp;
            t.push_back(tmp);
        }
        costs.push_back(t);
    }
    doCalculate(costs);
    return 0;
}
