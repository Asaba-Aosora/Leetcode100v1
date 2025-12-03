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

// 其实就是层序遍历，按层取最后一个节点
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            TreeNode* cur = nullptr;
            while(sz)
            {
                cur = q.front();
                q.pop();
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
                sz--;
            }
            ans.push_back(cur->val);
        }
        return ans;
    }
};