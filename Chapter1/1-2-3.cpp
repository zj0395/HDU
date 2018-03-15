#include<iostream>
using namespace std;

int main()
{
    char str[1024];
    while( cin.getline(str, 1024) && str[0] !='#' )
    {
        int sum = 0;
        for( int i=0; str[i];++i  )
        {
            if( str[i] != ' '  )
                sum += (str[i]-'A'+1)*(i+1);
        }
        cout<<sum<<"\n";
    }
    return 0;
}
