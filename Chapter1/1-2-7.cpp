#include<iostream>
using namespace std;

inline int getSum( int num, int base  )
{
    int ret = 0;
    while( num  )
    {
        ret += num % base;
        num /= base;
    }
    return ret;
}

bool equal( int num )
{
    int dec = getSum( num, 10  );
    int hex = getSum( num, 16 );
    if( dec == hex  )
        if ( dec == getSum( num, 12 ) )
            return true;
    return false;
}

int main()
{
    for( int i=2992; i<10000; ++i  )
        if( equal(i) )
            cout<<i<<"\n";
    return 0;
}
