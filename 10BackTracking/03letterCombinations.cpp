// 用哈希存数字对应的 **字符串**

class Solution {
    vector<string> ans;
    string t;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(int cur, string digits)
    {
        int len = digits.size();

        if(cur==len)
        {
            ans.push_back(t);   // len==0 时不要添加空字符串
            return;
        }

        string str = phoneMap[digits[cur]];
        for(char ch: str)
        {
            t.push_back(ch);
            dfs(cur+1, digits);
            t.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())    return {};
        dfs(0, digits);
        return ans;
    }
};