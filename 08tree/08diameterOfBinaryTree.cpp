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

// 最大深度==最长路径节点数-1==左子树最大节点数+右子树最大节点数+1(根节点)-1
class Solution {
    int maxD;
    int depth(TreeNode* root)
    {
        if(!root)   return 0;
        int leftD = depth(root->left);
        int rightD = depth(root->right);
        maxD = max(maxD, leftD+rightD+1);
        return max(leftD, rightD)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxD-1;      // 节点个数要-1才是路径长度
    }
};