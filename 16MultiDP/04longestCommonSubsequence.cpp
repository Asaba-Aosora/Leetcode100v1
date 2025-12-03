// dp[i][j]: 表示 text1中的[0:i]序列，和text2中的[0:j]序列的最大子序列长度
// 当 text1[i]==text2[j]时：dp[i][j] = dp[i-1][j-1] + 1
// 其他情况：dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// 注意：[0:i]序列指的是从0开始，长度为i，不是到下标为i

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();   // i
        int n = text2.size();   // j
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        // 初始化：dp[i][0] = dp[0][j] = 0 已经完成了
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                // 这里ij是dp里的，是长度，转化到index要-1
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};