#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num[4];
    bool first = true;
    while( 1 )
    {
        bool end = true;
        for(int i=0;i<4;++i)
        {
            cin>>num[i];
            if( num[i] )
                end = false;
        }
        if( end )
            break;
        if( !first )
        {
            cout<<"\n";
        }
        first=false;
        sort( num, num+4 );
        int current=-1;
        do
        {
            if( num[0] == 0 )
                continue;
            if( current != num[0] )
            {
                if( current != -1 )
                    cout<<"\n";
                current = num[0];
            }
            else
                cout<<" ";
            cout<<num[0]*1000+num[1]*100+num[2]*10+num[3];
        }while( next_permutation(num, num+4) );
        cout<<"\n";
    }
    return 0;
}
