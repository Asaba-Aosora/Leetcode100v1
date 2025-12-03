// 格式正确且连续的最长括号子串
// dp[i]: 以i结尾的最长括号子串长度
// 考虑两种方式：嵌套 || 加后缀

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size();
        if(sz<=1)   return 0;
        vector<int> dp(sz);
        int ans = 0;

        // 一趟遍历就处理了
        for(int i=0; i<sz; i++)
        {
            if(s[i]==')')
            {
                if(i>0 && s[i-1]=='(')
                {
                    dp[i] = (i>1 ? dp[i-2] : 0) + 2;
                }
                else if(i>0 && s[i-1]==')' && i>dp[i-1] && s[i-dp[i-1]-1]=='(')
                {
                    dp[i] = dp[i-1] + 2 + (i>dp[i-1]+1 ? dp[i-dp[i-1]-2] : 0);  // 还有前面的序列哦
                }
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};

int main()
{
    string s = "()(())";
    Solution slt;
    cout << slt.longestValidParentheses(s);

    return 0;
}