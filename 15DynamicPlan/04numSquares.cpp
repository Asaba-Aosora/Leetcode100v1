class Solution {
    vector<int> dp;
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=1; i<=n; i++)
        {
            // 这里要求dp[i]，也就是i由几个平方数组成
            int minn = INT_MAX;
            for(int j=1; j*j<=i; j++)
            {
                minn = min(minn, dp[i-j*j]);
            }
            dp[i] = minn+1;     // 这里要+1！因为前面减了一个平方数
        }
        return dp[n];
    }
};