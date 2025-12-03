#include <iostream>
#include <vector>

using namespace std;

// 不对，这里没判断 负-正-负 的情况
// 分正负性dp？
// 一个数组像我这样存 绝对值最大的正积， 另一个数组存 绝对值最大的负积
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+1);   // dp[i]: 以nums[i-1]结尾的子序列的最大乘积
//         dp[0] = 1;
//         int ans = INT_MIN;

//         for(int i=0; i<n; i++)
//         {
//             if(dp[i]==0 || nums[i]==0)
//             {
//                 dp[i+1] = nums[i];
//             }
//             else if((dp[i] ^ nums[i]) >= 0)
//             {
//                 // 用异或判断是否同号：同号，则符号位相同，异或结果为0，0作符号位时是正数 or 0 （两数相同时为0）
//                 dp[i+1] = dp[i]*nums[i];
//             }
//             else
//             {
//                 dp[i+1] = nums[i];
//             }
//             ans = max(ans, dp[i+1]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        vector<int> mindp(n);
        vector<int> maxdp(n);
        mindp[0] = maxdp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            // 分正负！max希望正*正、负*负，min希望正*负、负*正
            // 而max放的是正，min放的是负，需要 **交替** 运算
            if(nums[i]>0)
            {
                maxdp[i] = max(maxdp[i-1]*nums[i], nums[i]);
                mindp[i] = min(mindp[i-1]*nums[i], nums[i]);
            }
            else
            {
                maxdp[i] = max(mindp[i-1]*nums[i], nums[i]);
                mindp[i] = min(maxdp[i-1]*nums[i], nums[i]);
            }
            ans = max(ans, maxdp[i]);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {-1,-2,-9,-6};
    Solution slt;
    cout << slt.maxProduct(nums) << endl;

    return 0;
}