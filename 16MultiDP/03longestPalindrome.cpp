// 回文子串：首先自己是回文的，然后以回文串对称，如果对应位置是对应字母，则也是回文

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int pos = 0;
        int maxLen = 1;

        // 初始化两条斜线
        for(int i=0; i<n; i++)
        {
            dp[i][i] = true;
        }
        for(int i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                if(maxLen<2)
                {
                    pos = i;
                    maxLen = 2;
                }
            }
        }

        // dp，从下往上
        for(int i=n-3; i>=0; i--)
        {
            for(int j=i+2; j<n; j++)
            {
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                if(dp[i][j] && maxLen < j-i+1)
                {
                    maxLen = j-i+1;
                    pos = i;
                }
            }
        }

        return s.substr(pos, maxLen);
    }
};

// 成功但是有点慢。还有什么高级做法吗
// 可以剪枝！！如果一个回文中心这一步不能扩展，那以后都不能扩展了
