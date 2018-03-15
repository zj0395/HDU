#include<iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    double dia, time;
    int revo;
    int i=0;
    while( cin>>dia>>revo>>time && revo != 0  )
    {
        dia /= 5280 * 12;
        dia *= revo * 3.1415927;
        time= 3600 * dia / time;
        cout<<"Trip #"<<++i<<": " << dia <<" " << time<<"\n";
    }
    return 0;
}
