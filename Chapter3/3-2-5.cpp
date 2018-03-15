//丑数
#include<iostream>
using namespace std;
#define SIZE 5842
int main()
{
    int ret[SIZE] = {1};
    int two = 0, three = 0, five = 0, seven = 0;
    for( int i=1; i<SIZE; ++i )
    {
        ret[i] = min( min(2*ret[two], 3*ret[three]),
                      min(5*ret[five], 7*ret[seven]));
        if(ret[i] == ret[two]*2) ++two;
        if(ret[i] == ret[three]*3 ) ++three;
        if(ret[i] == ret[five]*5 ) ++five;
        if(ret[i] == ret[seven]*7 ) ++seven;
    }
    int n;
    char numth[4][3] = {"st", "nd", "rd", "th"};
    while( cin>>n && n )
    {
        int num = 0;
        if( n%10==1 && n%100!=11 )num=0;
        else if( n%10==2 && n%100!=12 )num=1;
        else if( n%10==3 && n%100!=13 )num=2;
        else num = 3;
        cout<<"The "<<n<<numth[num]<<" humble number is "<<ret[n-1]<<".\n";
    }
}
