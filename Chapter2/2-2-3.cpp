#include<iostream>
#include<cstring>
using namespace std;
#define MAX 65
#define CIN(ARRAY, S)\
{\
    for(int i=0;i<S;++i)\
    {\
        cin>>tmp;ARRAY[tmp]=1;\
    }\
}
bool hanoi(int N,int*m, int*p, int*q)
{
    if( N==0 )
        return true;
    if( p[N] )
        return false;
    if( m[N]  )
        return hanoi(N-1,m,q,p);
    if( q[N] )
        return hanoi(N-1,p,m,q);
}
int main()
{
    int num;
    cin>>num;
    int N, M, P, Q, tmp;
    int m[MAX], p[MAX], q[MAX];
    while(num--)
    {
        memset( m, 0, sizeof(m) );
        memset( p, 0, sizeof(p) );
        memset( q, 0, sizeof(q) );
        cin>>N>>M;
        CIN(m, M);
        cin>>P;
        CIN(p, P);
        cin>>Q;
        CIN(q, Q);
        cout<< (hanoi(N, m,p,q) ? "true\n":"false\n");
    }
}
