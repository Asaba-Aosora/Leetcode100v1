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

// 思路倒是很简单：中序遍历的第k个
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int cnt=0;
        stk.push(root);
        root = root->left;
        while(!stk.empty() || root)     // 简写的时候一定要注意什么时候是非空！不然就老老实实写全
        {
            if(!root)
            {
                root = stk.top();
                stk.pop();
                cnt++;
                if(cnt==k)
                {
                    break;
                }
                root = root->right;
            }
            else        // 这儿可以写while的
            {
                stk.push(root);
                root = root->left;
            }
        }
        return root->val;
    }
};


// 法二：如果需要频繁查询第k小，就可以先进行一次预处理、把每个子树的节点数存起来


// 法三：改成avl平衡树