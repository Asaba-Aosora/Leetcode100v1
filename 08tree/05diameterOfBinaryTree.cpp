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

// 这个也可以递归！每个节点都看成一个子树，左深度+右深度+1 = 最长路径上的节点数
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
    }
};