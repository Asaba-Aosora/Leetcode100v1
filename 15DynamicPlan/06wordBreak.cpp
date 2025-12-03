#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 回溯，但是会被奇妙样例搞超限(无语)
// s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
// class Solution {
//     bool backtrace(const string& s, const vector<string>& wordDict, int cur)
//     {
//         if(cur==s.size())     return true;
//         for(auto& str : wordDict)
//         {
//             if(s.size()-cur>=str.size() && equal(str.begin(), str.end(), s.begin()+cur))     // 防止越第二个的界
//             {
//                 bool flag = backtrace(s, wordDict, cur+str.size());
//                 if(flag)    return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         return backtrace(s, wordDict, 0);
//     }
// };

// 还是用dp吧
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);      // dp[i]：长度为i的substr能否被组成
        dp[0] = true;
        for(int i=0; i<len; i++)   // 这儿是s的下标
        {
            for(auto& str : wordDict)
            {
                int strlen = str.size();
                if(strlen<=i+1 && dp[i+1-strlen] && equal(str.begin(), str.end(), s.begin()+i+1-strlen))
                {
                    dp[i+1] = true;     // 这儿是长度
                }
            }
        }
        return dp[len];
    }
};

int main()
{
    Solution slt;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout << slt.wordBreak(s, wordDict);

    return 0;
}