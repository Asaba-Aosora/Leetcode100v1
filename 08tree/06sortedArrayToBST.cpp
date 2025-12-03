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

// 平衡二叉搜索树：主要是平衡树的插入+旋转
// 添加节点--检查是否平衡--旋转
// 好吧，其实一开始是数组，那就不需要旋转了。直接选择中间值作为根节点就好
// 把中间节点作为根，左边转化成平衡树，右边转化成平衡树
class Solution {
    TreeNode* mysort(vector<int>& nums, int left, int right)
    {
        if(left>=right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = mysort(nums, left, mid);
        cur->right = mysort(nums, mid+1, right);
        return cur;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = mysort(nums, 0, nums.size());
        return ans;
    }
};