// 最长递增子序列，但是不要求连续
#include <iostream>
#include <vector>
using namespace std;

// 法一：dp
// 注意：这里的dp[i]一定是以i结尾的子串！包含nums[i]的
// 求dp[i+1]的时候，用 max(dp[0], dp[1], ... , dp[i]) + nums[i+1]
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int len = nums.size();
//         vector<int> dp(len+1);
//         // dp[0] = 0;
//         dp[1] = 1;
//         int ans = 1;
//         for(int i=1; i<len; i++)
//         {
//             // 此处的i是nums的下标，在dp中要+1
//             int pos = 0;    // 最大值所在的下标，还要满足nums[pos]<nums[i]
//             for(int j=0; j<i; j++)
//             {
//                 // j也是nums里的下标
//                 if(nums[j]<nums[i])
//                 {
//                     pos = dp[j+1]>dp[pos] ? j+1 : pos;
//                 }
//             }
//             dp[i+1] = dp[pos]+1;
//             ans = max(ans, dp[i+1]);
//         }
//         // 最后应该返回最大值，而最大值不一定在最后结尾
//         return ans;
//     }
// };

// 法二：贪心+二分
// 维护一个数组d，d[i]表示长度为i+1的子序列的最小结尾
// 遍历nums，对nums[k]和d[i]进行比较：nums[k]>d[i]，往后放；否则就在前面找
class Solution {
    void binarySearch(vector<int>& d, int num)
    {
        int left=0, right=d.size();
        while(left!=right)
        {
            int mid = (left+right)/2;
            // 相等时不用管
            if(d[mid]==num)     return;
            // 目的是找到“该插入的地方”，即比它大的第一个数
            if(d[mid]<num)
            {
                // 右边的区间
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        d[left] = num;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(1);
        d[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]>d.back())
            {
                d.push_back(nums[i]);
            }
            else if(nums[i]<d.back())
            {
                binarySearch(d, nums[i]);
            }
        }
        return d.size();
    }
};


int main()
{
    Solution slt;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout << slt.lengthOfLIS(nums);

    return 0;
}