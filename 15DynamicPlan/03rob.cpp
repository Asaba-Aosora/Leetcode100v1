// 不能相邻，最高金额
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化dp表: 对角线
        for(int i=0; i<n; i++)
        {
            dp[i][i] = nums[i];
        }
        // 对角线的上一斜线
        for(int i=0; i<n-1; i++)
        {
            dp[i][i+1] = max(dp[i][i], dp[i+1][i+1]);
        }

        // 其他斜线
        for(int k=2; k<n; k++)
        {
            for(int i=0; i<n-k; i++)
            {
                dp[i][i+k] = max(dp[i][i+k-1], dp[i][i+k-2]+nums[i+k]);
            }
        }

        return dp[0][n-1];
    }
};