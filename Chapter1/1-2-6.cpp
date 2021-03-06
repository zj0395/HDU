#include<iostream>
#include<cstring>
using namespace std;

#define ASCIISIZE 256
#define MAXSIZE   52
char* buildMap()
{
    char * asciiMap = new char[ ASCIISIZE ];
    for( int i=0; i<ASCIISIZE; ++i  )
        asciiMap[i] = i;
    const char* vowel = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* vowelTransform = "BCDEFGHIJKLMNOPQRSTUVWXYZA";
    int tranSize = strlen(vowel);
    for( int i=0; i<tranSize; ++i )
        asciiMap[ vowel[i] ] = vowelTransform[i];
    return asciiMap;
}

void transform( char str[]  )
{
    int len = strlen(str);
    static char* asciiMap = buildMap();
    for( int i=0; i<len; ++i )
        str[i] = asciiMap[ str[i] ];
    cout<<str<<"\n";
}

int main()
{
    int lineNum;
    cin>>lineNum;
    getchar();
    char str[MAXSIZE];
    for( int i=0; i<lineNum; ++i )
    {
        cin.getline(str, MAXSIZE);
        cout<<"String #"<<i+1<<"\n";
        transform( str  );
        cout<<"\n";
    }
    return 0;
}
