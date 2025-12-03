// 柱状图中的最大矩形

// 主要思路: 遍历每个高, 然后找其对应的宽
// 宽怎么找? 找到左右分别小于当前高的, 最近的坐标 --> 符合单调栈. but, 单调栈好找左边, 怎么找右边?
// 利用单调栈的更新条件! heights[i] >= stk.top() 时, i 入栈; else i 即为右边界, 在stk里找需要遍历的高度
// 注意等于时要入栈! 保证下个数的左边界是对的!
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stk;
        stk.push(-1);   // 建立一个手动的左边界
        int n = heights.size();
        for(int i=0; i<n; i++)
        {
            if(stk.empty())
            {
                // 实际上不可能走到这一步的, 因为存在 -1 的手动边界
                stk.push(i);
                continue;
            }
            int top = stk.top();
            int left_h = top==-1 ? -1 : heights[top];
            if(left_h>heights[i])
            {
                // 根据i为右边界, 往左找
                while(left_h>heights[i])
                {
                    // 当前的height就是left_h, 然后要找左边界
                    stk.pop();
                    int l = stk.top();
                    int w = i-l-1;
                    ans = max(ans, w*left_h);
                    
                    left_h = l==-1 ? -1 : heights[l];
                }
                stk.push(i);
            }
            else
            {
                // 加进来
                stk.push(i);
            }
            // 相等的时候就不管了, 因为以左边那个开始算, 肯定宽要更大
            // 不对! 万一中间的更小就不好了
            // 都加进来吧, 反正多处理一下没问题的()
            // 明白了, 存相等是为了 "下一个数找左边界" 方便, 不存的话左边界就错了. 而存进去, 也不会对正确答案造成影响
        }
        // 还有最后的递增部分需要处理
        int r = n;
        int top = stk.top();
        int h = top==-1 ? -1 : heights[top];
        stk.pop();
        while(!stk.empty())
        {
            top = stk.top();
            ans = max(ans, h*(r-top-1));
            h = top==-1 ? -1 : heights[top];
            stk.pop();
        }

        return ans;
    }
};

int main()
{
    Solution slt;
    vector<int> heights = {0,1,0,1};
    cout << slt.largestRectangleArea(heights);

    return 0;
}