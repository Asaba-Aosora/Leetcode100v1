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

// 先递归：分别检查左右子树是否相等
class Solution {
    bool mySymmetric(TreeNode* left, TreeNode* right)
    {
        if(!left && !right)         return true;
        if(!left || !right)         return false;
        if(left->val!=right->val)   return false;

        return mySymmetric(left->left, right->right) && mySymmetric(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return mySymmetric(root->left, root->right);
    }
};


// 迭代法。其实和递归差别不大，只不过是维护一个队列、比较相邻两个node的值
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* l = q.front();    q.pop();
            TreeNode* r = q.front();    q.pop();
            if(!l && !r)    continue;       // 空指针这里处理，就不用添加节点的时候写得很麻烦了
            if(!l || !r)    return false;
            if(l->val != r->val)    return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};