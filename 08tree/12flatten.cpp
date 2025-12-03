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

// 感觉可以递归，中+左+右
class Solution {
    pair<TreeNode*, TreeNode*> myflatten(TreeNode* root)
    {
        if(root==nullptr)       return {0, 0};
        auto r1 = myflatten(root->left);
        auto r2 = myflatten(root->right);
        TreeNode *lhead = r1.first;
        TreeNode *ltail = r1.second;
        TreeNode *rhead = r2.first;
        TreeNode *rtail = r2.second;

        root->left = nullptr;
        TreeNode *cur = root;
        
        if(lhead)
        {
            cur->right = lhead;
            cur = ltail;
        }
        if(rhead)
        {
            cur->right = rhead;
            cur = rtail;
        }
        return {root, cur};

    }
public:
    void flatten(TreeNode* root) {
        myflatten(root);
    }
};