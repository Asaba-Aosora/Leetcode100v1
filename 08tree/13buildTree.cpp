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

// 感觉递归很合适
class Solution {
    vector<int> preorder, inorder;
    int sz;

    TreeNode* mybuild(int prehead, int pretail, int inhead, int intail)
    {
        // 防止越界：没有右子树/左子树时
        // 为什么加了 "inhead>intail" 就对了呢，按理来说这个和 prehead>pretail 等价啊
        if(prehead>=sz || prehead>pretail || inhead>intail)     return 0;

        int val = preorder[prehead];
        TreeNode *root = new TreeNode(val);

        if(prehead==pretail)
        {
            return root;
        }

        int index = inhead;
        while(inorder[index]!=val)
        {
            index++;
        }
        // 现在index是inorder中root的下标，接下来放左序列和右序列
        int len = index -1 - inhead;
        root->left = mybuild(prehead+1, prehead+1+len, inhead, index-1);
        root->right = mybuild(prehead+1+len+1, pretail, index+1, intail);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder;
        inorder = _inorder;
        sz = preorder.size();
        return mybuild(0, sz-1, 0, sz-1);
    }
};


// 可以用哈希改进递归法！只要先遍历一遍中序数组，再根据先序找就是O(1)了
class Solution {
    unordered_map<int, int> map;    // 中序遍历的<值，下标>

    TreeNode* mybuild(vector<int>& preorder, vector<int>& inorder, int prehead, int pretail, int inhead, int intail)
    {
        if(prehead>pretail || inhead>intail)    return nullptr;
        int index = map[preorder[prehead]];
        TreeNode *cur = new TreeNode(preorder[prehead]);
        
        cur->left   = mybuild(preorder, inorder, prehead+1, index-inhead+prehead, inhead, index-1);
        cur->right  = mybuild(preorder, inorder, pretail+index+1-intail, pretail, index+1, intail);

        return cur;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++)
        {
            map.insert({inorder[i], i});
        }
        return mybuild(preorder, inorder, 0, n-1, 0, n-1);
    }
};