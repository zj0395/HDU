#include<iostream>
#include<algorithm>
using namespace std;
void read(int*array, int num)
{
    int i=0;
    while( num-- )
        cin>>array[i++];
    sort( array, array+i );
}
int main()
{
    int first[100];
    int second[100];
    int num;
    while( cin>>num && num )
    {
        read( first, num );
        read( second, num );
        int s1=0, s2=0;
        for( int i=0; i<num; ++i )
        {
            if( first[i] > second[i] )
                s1+=2;
            else if( first[i] < second[i] )
                s2+=2;
            else
            {
                ++s1;++s2;
            }
        }
        cout<<s1<<" vs "<<s2<<"\n";
    }
    return 0;
}
