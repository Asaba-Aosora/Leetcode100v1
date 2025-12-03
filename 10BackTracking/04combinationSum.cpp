#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//     vector<int> t;
//     vector<vector<int>> ans;
//     void backtrack(vector<int>& candidates, int target)
//     {
//         if(target==0)
//         {
//             ans.push_back(t);
//             return;
//         }

//         for(int cur: candidates)
//         {
//             if(cur<=target)
//             {
//                 t.push_back(cur);
//                 backtrack(candidates, target-cur);
//                 t.pop_back();
                
//                 // backtrack(candidates, target);   // 写在这里也要死循环：没有排除当前这个数
//             }
//             // backtrack(candidates, target);   // 写在这里要死循环！！每个数都小于target时就很难过了
//         }
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         backtrack(candidates, target);
//         return ans;
//     }
// };

// 换一种写法：只遍历一次candidates，然后对每一个位置都选择 用/不用， 再递归
class Solution {
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int index, vector<int>& candidates, int target)
    {
        int n = candidates.size();
        if(target==0)
        {
            ans.push_back(t);
            return;
        }
        if(target<0 || index==n)    return;

        // 选这个数
        t.push_back(candidates[index]);
        dfs(index, candidates, target-candidates[index]);
        t.pop_back();

        // 不选
        dfs(index+1, candidates, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, candidates, target);
        return ans;
    }
};

int main()
{
    Solution slt;
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    slt.combinationSum(candidates, target);

    return 0;
}