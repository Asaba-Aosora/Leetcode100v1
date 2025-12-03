// 分割回文串
// 太天才了，置一个方阵，dp[i][j] (i<=j) 即表示 (i, j) 的子串为回文
// 1. 对角线上 dp[i][i]: 都是单个字符, 一定回文
// 2. 紧邻对角线的一条斜线 dp[i][i+1]: 看相邻两字母是否相等
// 3. 其他 dp[i]][j]: dp[i+1][j-1] && s[i]==s[j]    子问题为回文+新情况还是回文
// 回溯时就是找一条斜线, 满足斜线上都是回文? 不对, 只遍历当前串的所有分割情况 -- 得到下一次的串

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<string> t;   // 当前的分割

    void dfs(const string& s, int i, int n)
    {
        if(i==n)
        {
            ans.push_back(t);
            return;
        }

        for(int j=i; j<n; j++)
        {
            // 遍历从 (i, i) 开始的所有子串
            if(dp[i][j])
            {
                // 这个子串是回文的, 添加到答案, 继续
                t.push_back(s.substr(i, j-i+1));
                dfs(s, j+1, n);
                t.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n));
        // 初始化dp表: 对角线
        for(int i=0; i<n; i++)
        {
            dp[i][i] = true;
        }
        
        for(int i=0; i<n-1; i++)
        {
            dp[i][i+1] = s[i] == s[i+1];
        }

        for(int i=n-2; i>-1; i--)    // 跳过(n-1, n-1), 避免越界
        {
            for(int j=i+2; j<n; j++)    // 保持 j>i, 且 (i,i+1) 是前一步更新过的, 不能损坏这部分数据
            {
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];  // 要先更新 i+1 行, 再更新 i 行!
            }
        }

        dfs(s, 0, n);

        return ans;
    }
};

int main()
{
    string str = "cbbbcc";
    Solution slt;
    auto ans = slt.partition(str);
    for(auto i: ans)
    {
        for(auto j: i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}