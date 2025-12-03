class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划做？到当前位置的最大和：dp[i] = max(dp[i-1]+nums[i], nums[i])，再随时更新ans
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1; i<len; i++)
        {
            // 其实这里可以用滚动数组优化，毕竟只需要dp[i-1]，不需要更前面的
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ans = max(dp[i], ans);
        }


        return ans;
    }
};