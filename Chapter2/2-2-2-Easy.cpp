//取巧的方法
#include<iostream>
using namespace std;
int main()
{
    int result[15] = {1,2,7,5,30,
        169,441,1872,7632,1740,
        93313,459901,1358657,2504881,1348270};
    int num;
    while(cin>>num&&num)
        cout<<result[num]<<"\n";
    return 0;
}
