// 子集：元素唯一、不排顺序
// 二进制！位图！太聪明了
// 遍历 2^n
class Solution {
    vector<int> t;      // 一个子集
    vector<vector<int>> ans;    // 子集的集合
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        for(int mask=0; mask<(1<<n); mask++)
        {
            // 用掩码来遍历所有情况
            t.clear();      // 清除t中已有元素
            for(int i=0; i<n; i++)
            {
                // 往t里填这次的子集
                if((1<<i)&mask)     // 两点：1.不要写成&&  2.记住要左移！
                {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};


// 递归+回溯
// 确定 [cur, n-1] --> cur 有 放进去/不放进去 两种状态 --> 选择一种 --> 子问题[cur+1, n-1] --> 回溯选择另一种cur
class Solution {
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums)
    {
        int n = nums.size();
        if(cur==n)    return;

        t.push_back(nums[cur]);
        dfs(cur+1, nums);
        if(cur==n-1)    ans.push_back(t);
        t.pop_back();

        dfs(cur+1, nums);
        if(cur==n-1)    ans.push_back(t);
        // t.pop_back();        // 没有放进去当然就不需要弹出

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};