/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 方向必须是向下的，所以其实不用考虑折线的情况，直接分治、把每个节点当成根来做就好了
class Solution {
    // 这里是“一个根下符合目标的路径数”
    int rootSum(TreeNode* root, int targetSum)
    {
        if(!root)   return 0;
        int ans = 0;
        if(root->val == targetSum)  ans++;
        ans += rootSum(root->left, targetSum - root->val);
        ans += rootSum(root->right, targetSum - root->val);
        return ans;
    }

public:
    // 这里要考虑不同的根
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)   return 0;
        int ans = rootSum(root, targetSum);
        ans += pathSum(root->left, targetSum);      // 这儿要递归调用pathSum，因为pathSum才是考虑不同起点的
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};


// 还可以用前缀和做，避免重复计算
// 深度搜索遍历
// 哦！不是自底向上的前缀和，是自顶向下的前缀和，一边遍历一边就维护了
// 1. 前缀和：prefix[j]-prefix[i] == targetSum，即(i,j)这一段的和为targetSum，移项来求
// 2. dfs其实是递归，先左后右，记得清理掉“现在”的数据
class Solution {
    unordered_map<long long, int> prefix;   // 前缀和，次数
    int dfs(TreeNode* root, long long cur, int targetSum)
    {
        int ret = 0;
        if(!root)   return ret;

        cur += root->val;

        if(prefix.count(cur-targetSum))
        {
            ret = prefix[cur-targetSum];
        }

        prefix[cur]++;

        ret += dfs(root->left, cur, targetSum);
        ret += dfs(root->right, cur, targetSum);

        prefix[cur]--;

        return ret;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;      // 为了保证第一次到 cur-targetSum==0 时，能够正确返回。而且，不到这个情况也触发不了这个return
        return dfs(root, 0, targetSum);
    }
};