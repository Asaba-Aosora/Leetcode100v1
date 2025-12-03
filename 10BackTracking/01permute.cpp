// 全排列
// 回溯: "回到上一步", 抛弃当前解再尝试

class Solution {
    void backtrack(int first, int len, vector<int>& output, vector<vector<int>>& res)
    {
        if(first==len)
        {
            // 排序完成了，可以把当前数组 output 添加进结果 res
            res.push_back(output);
            return;
        }

        // 未完成
        for(int i=first; i<len; i++)
        {
            swap(output[i], output[first]);
            backtrack(first+1, len, output, res);
            swap(output[i], output[first]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0, nums.size(), nums, res);
        return res;
    }
};