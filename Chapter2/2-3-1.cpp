#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 1001
void cal(char* l, char*r, int m,int n)
{
    int opt=0;
    static char result[SIZE+1];
    int i=0;
    while(m||n)
    {
        opt+= (m>0?(l[--m]-'0'):0) + (n>0?(r[--n]-'0'):0);
        result[i++]=opt%10+'0';
        opt/=10;
    }
    while(i)
        cout<<result[--i];
    cout<<"\n";
}
int main()
{
    int N;
    cin>>N;
    char left[1001], right[1001];
    int i=0;
    while( N-- )
    {
        cin>>left>>right;
        cout<<"Case "<<++i<<":\n";
        cout<<left<<" + "<<right<<" = ";
        cal( left, right, strlen(left), strlen(right) );
        if( N )
            cout<<"\n";
    }
}
