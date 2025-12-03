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


// 递归！真tmd聪明
// 深度优先这么用就很舒服了
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int depthL = maxDepth(root->left);
        int depthR = maxDepth(root->right);
        int maxD = max(depthL, depthR) + 1;
        return maxD;
    }
};

// 广度优先--改成按层搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left)    q.push(cur->left);
                if(cur->right)   q.push(cur->right);
                sz--;
            }
            depth++;
        }
        return depth;
    }
};