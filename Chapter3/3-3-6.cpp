// 01背包问题
// 去除5元后, 剩余解01背包问题即可
// https://blog.csdn.net/acm_1361677193/article/details/47262861
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_NUM 1001
int main()
{
    int foodPrice[MAX_NUM];
    int num;
    int money;
    int DP[MAX_NUM];
    while( cin>>num && num  )
    {
        memset(DP, 0, sizeof(DP));
        for(int i=0; i<num; ++i)
        {
            cin>>foodPrice[i];
        }
        cin>>money;
        // 只需要把最大的放到最后
        std::sort(foodPrice, foodPrice+num);

        for( int i=0; i<num-1; ++i  )
            for( int j=money-5; j>=foodPrice[i]; --j )
            {
                DP[j] = std::max(DP[j], DP[j-foodPrice[i]]+foodPrice[i]);
            }

        std::cout<< (money<5?money:money-DP[money-5]-foodPrice[num-1]) <<"\n";
    }
    return 0;
}
