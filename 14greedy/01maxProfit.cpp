/*
    这玩意用贪心做真的保证利润最大吗? 
    "历史"最低点! 考虑卖出之前的最低买入, 而非全局最低
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> dp(n);
//         dp[0]=0;
//         int low=0;
//         for(int i=1; i<n; i++)
//         {
//             if(prices[i] > prices[low])
//             {
//                 dp[i] = max(dp[i-1], prices[i]-prices[low]);
//             }
//             else
//             {
//                 dp[i] = dp[i-1];
//             }
//             if(prices[i] < prices[low])
//             {
//                 low = i;
//             }
//         }
//         return dp[n-1];
//     }
// };

/*
    题解的做法更"贪心"啊, 只记录最大利润和最小历史值, 不像我这个要把全部存起来. 其实好理解, dp不用开数组, 只需要两格就ok了
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPri = 1e6;
        for(int price : prices)
        {
            maxPro = max(maxPro, price - minPri);
            minPri = min(minPri, price);
        }
        return maxPro;
    }
};

int main()
{
    Solution slt;
    vector<int> prices = {7,1,5,3,6,4};
    int ans = slt.maxProfit(prices);
    cout << ans << endl;

    return 0;
}