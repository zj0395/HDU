#include<iostream>
#include <algorithm>
using namespace std;

#define MAX 1024

void read( int* array, int num )
{
    int i=0;
    while( num-- )
        cin>>array[i++];
    sort( array, array+i, [](int a, int b)
            {
                return a > b;
            });
}

int main()
{
    int first [MAX];
    int second[MAX];
    int nums;
    while( cin>>nums && nums )
    {
        read(first, nums);
        read(second, nums);
        int wins = 0;
        int begin = 0;
        int firstI=0, secondI=0;
        int firstNum=nums-1, secondNum = nums-1;
        while( firstI<=firstNum  )
        {
            if( first[firstI] > second[secondI]  )
            {
                ++wins;
                ++firstI;
                ++secondI;
            }
            else if( first[firstI] < second[secondI] )
            {
                --wins;
                --firstNum;
                ++secondI;
            }
            else
            {
                if( first[ firstNum ] > second[secondNum]  )
                {
                    --firstNum;
                    --secondNum;
                    ++wins;
                }
                else if( first[firstNum] < second[secondI] )
                {
                    --firstNum;
                    ++secondI;
                    --wins;
                }
                else
                {
                    --firstNum;
                    ++secondI;
                }
            }
        }
        cout<<200*wins<<endl;
    }
    return 0;
}
