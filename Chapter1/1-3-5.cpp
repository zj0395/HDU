#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int number[10001];
    int num;
    while( cin>>num )
    {
        for( int i=0; i<num; ++i  )
            cin>>number[i];
        sort(number, number+num);
        int b=0, e=num-1;
        for(int i=0; i<num; ++i)
        {
            cout<< (i%2==0 ? number[e--] : number[b++]);
            if( i!=num-1 )
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
