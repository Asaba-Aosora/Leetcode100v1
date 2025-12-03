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

// 二叉树的中序遍历，ez
// 递归，左中右，先存中间节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)
        {
            return vector<int>{};
        }

        auto left = inorderTraversal(root->left);
        auto right = inorderTraversal(root->right);

        vector<int> ans;
        ans.reserve(left.size()+right.size()+1);    // 预留空间，但不改变size的大小和it的位置
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

// 我靠递归还能优化，写两个函数
class Solution {
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 主函数，负责初始化vector
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// 迭代法：用栈存root
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur)
        {
            while(cur->left)
            {
                stk.push(cur);
                cur = cur->left;
            }
            // 走到左下角，开始回溯
            ans.push_back(cur->val);
            while(!cur->right && !stk.empty())
            {
                cur = stk.top();
                ans.push_back(cur->val);
                stk.pop();
            }
            // stk为空 || 有右节点
            cur = cur->right;
        }

        return ans;
    }
};

// 官解的迭代法更简洁
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
            // root 表示待处理的子树，stk存的是待处理的根节点，二者都为0时表示没有待处理的东西了
            // 我写得复杂是因为我要保持root非零，但其实按这个思路，当root为0的时候，就从stk里选第一个树出来处理就好了
            while(root)
            {
                stk.push(root);
                root = root->left;
            }

            // 走到这里必定root==0，不需要再判断一次
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);

            root = root->right;
        }
        return ans;
    }
};

// Morris法我就跟着打一遍算了
// 其实就是线索化二叉树
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* prev;
        // 处理每一个节点: 找左子树的最右节点为其前驱
        while(root)
        {
            // 如果没有左子树，那么就没有前驱，自己上--再往右
            if(!root->left)
            {
                ans.push_back(root->val);
                root = root->right;     // 很巧妙！叶子节点时，right就是其后继，不会为空
                continue;
            }
            // 有左子树：找前驱
            if(root->left)
            {
                prev = root->left;
                // 找最右节点
                while(prev->right && prev->right!=root)
                {
                    prev = prev->right;
                }

                if(!prev->right)
                {
                    // 为空，说明还没走到这里过
                    prev->right = root;
                    root = root->left;
                }
                else
                {
                    // 已经走过了，删除链接，root进入答案
                    prev->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }

            }

        }
        return ans;
    }
};