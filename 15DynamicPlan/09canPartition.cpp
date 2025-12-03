// 贪心？一个数加入后，要使两边的差值变小
// 不对
// 好吧这是 NP完全问题，贪心这种遍历一遍数组的 O(n) 是做不出来的

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end(), greater<int>());
//         int diff = nums[0];     // 把nums[0]放进vec1, vec2还为空
//         for(int i=1; i<n; i++)
//         {
//             if(diff>0)
//             {
//                 diff -= nums[i];
//             }
//             else
//             {
//                 diff += nums[i];
//             }
//         }

//         return diff==0;
//     }
// };


// 背包问题：选择正好和为总和的一半的数据
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n<2)     return false;
        int target = accumulate(nums.begin(), nums.end(), 0);
        int max_value = *max_element(nums.begin(), nums.end());
        if(target&1)    return false;   // 和为奇数，直接排除
        target /= 2;    // 现在target变成和的一半
        if(max_value>target)    return false;

        // 现在保证了基本的条件，可以开始dp了
        vector<bool> dp(target+1, false);   // 由二维数组简化来的，dp[i] 是“能凑到i”
        // 迭代第k次，就是nums[0]-nums[k-1]的序列里，可以凑到i
        dp[0] = true;

        for(int i=0; i<n; i++)
        {
            // nums[i]选不选的问题
            for(int j=target; j>=0 && j>=nums[i]; j--)
            {
                // 从大到小，因为是由二维数组简化得到一维数组，所以必须保证“前面的数据”是前面的，而不是刚刚产生的
                dp[j] = dp[j] | dp[j-nums[i]];
            }
            if(dp[target])  return true;
        }
        return false;
    }
};