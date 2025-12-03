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

// 和我的设想类似，维护两个变量，一个表示当前最大路径和，一个表示从当前节点往下的最大路径和，递归
// 不对，还要考虑负数
// 这个为啥这么慢呢
class Solution {
    int ans = INT_MIN;
    int maxDepth(TreeNode* root)
    {
        if(!root)   return 0;
        int ret = root->val;
        int left = max(0, maxDepth(root->left));
        int right = max(0, maxDepth(root->right));
        ret += max(left, right);
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root)   return 0;
        int left = max(0, maxDepth(root->left));        // 加一个 max(0, ...)，完美排除负数的干扰
        int right = max(0, maxDepth(root->right));
        ans = max(ans, left+right+root->val);
        maxPathSum(root->left);
        maxPathSum(root->right);
        return ans;
    }
};

class Solution {
    int ans = INT_MIN;
    int maxDepth(TreeNode* root)
    {
        if(!root)   return 0;
        int ret = root->val;
        int left = max(0, maxDepth(root->left));
        int right = max(0, maxDepth(root->right));
        ans = max(ans, left+right+root->val);   // ans用全局变量维护，所以可以直接在这里就维护了，不需要单独再算一次
        ret += max(left, right);
        return ret;     // 返回的时候就按一直往下的最大路径和返回就ok
    }
public:
    int maxPathSum(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};