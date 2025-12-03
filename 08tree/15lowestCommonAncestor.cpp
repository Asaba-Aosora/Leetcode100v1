/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归
// 判定条件：要么左右子树分别有pq，要么根节点为p(q), 子树中有q(p)
class Solution {
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // 返回值是，这个root的子树中有p或有q
        if(!root)   return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        if((lson&&rson) || ((root==p || root==q) && (lson || rson)))
        {
            ans = root;
        }

        return lson || rson || root==p || root==q;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};