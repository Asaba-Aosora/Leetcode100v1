// 有效括号序列，经典题目
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch: s)
        {
            if(ch=='(' || ch=='{' || ch=='[')
            {
                stk.push(ch);
            }
            else
            {
                if(stk.empty()) return false;
                char tmp = stk.top();
                stk.pop();
                if(tmp=='(' && ch==')') continue;
                if(tmp=='{' && ch=='}') continue;
                if(tmp=='[' && ch==']') continue;
                return false;
            }
        }
        return stk.empty() ? true : false;
    }
};