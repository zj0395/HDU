#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct OneRoom
{
    OneRoom( int j, int f  ): java(j), food(f), ratio(1.0*j/f){}
    int java;
    int food;
    double ratio;
};

int main()
{
    int M,N;
    int tmpJ, tmpF;
    while( cin>>M>>N && N != -1  )
    {
        vector<OneRoom> vec;
        for( int i=0; i<N; ++i )
        {
            cin >>tmpJ >>tmpF;
            vec.push_back( OneRoom(tmpJ, tmpF)  );
        }
        std::sort( vec.begin(), vec.end(),
                [](OneRoom&left, OneRoom&right)
                {
                    return left.ratio > right.ratio;
                });
        double sum = 0;
        for( int i=0; i<vec.size() && M>0; ++i  )
        {
            if( M <= vec[i].food  )
            {
                sum += M * 1.0 / vec[i].food * vec[i].java;
                M = 0;
            }
            else
            {
                sum += vec[i].java;
                M -= vec[i].food;
            }
        }
//        cout<<fixed<<setprecision(3)<<sum<<"\n";
        printf("%.3lf\n",sum);
    }
    return 0;
}
