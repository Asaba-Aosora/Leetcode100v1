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

// 二叉搜索树：中序遍历严格递增
// 不对，不能主线右子树的左叶子小于根的情况
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(!root)   return true;
//         if(root->left && root->left->val>=root->val)    return false;
//         if(root->right && root->right->val<=root->val)  return false;
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };

// 还是来中序遍历递增算了
class Solution {
    // int min_val = INT_MIN;       // 如果root->val==INT_MIN，就会出错。所以，最好的办法是设一个指针来跟踪前一个值
    int *min_val = nullptr;
    bool flag = true;

    // 中序遍历：先找左子节点，再自己，再右子节点
    void inordered(TreeNode* root)
    {
        if(!flag)   return;
        if(!root)   return;
        inordered(root->left);
        if(!min_val)
        {
            min_val = &root->val;
        }
        else if(*min_val<root->val)
        {
            min_val = &root->val;
        }
        else
        {
            flag = false;
            return;
        }
        inordered(root->right);
        
    }
public:
    bool isValidBST(TreeNode* root) {
        inordered(root);
        return flag;
    }
};