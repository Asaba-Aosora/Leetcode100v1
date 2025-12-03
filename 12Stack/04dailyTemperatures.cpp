// 单调栈：栈底到栈顶递减，表示还未找到 “后续高温” 的元素
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> stk;    // 这里存的是下标
        for(int i=0; i<n; i++)
        {
            if(stk.empty())
            {
                stk.push(i);
                continue;
            }
            while(!stk.empty())
            {
                int top = stk.top();
                if(temp[i]>temp[top])
                {
                    ans[top] = i - top;
                    stk.pop();
                }
                else
                {
                    break;
                }
            }
            stk.push(i);
        }
        // 不要这一段也能过，因为初始化为0
        // // 最后根据stk里剩下的元素，来给没找到后续的归零
        // while(!stk.empty())
        // {
        //     int top = stk.top();
        //     stk.pop();
        //     ans[top] = 0;
        // }
        return ans;
    }
};