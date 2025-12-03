/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 这是直接复制到数组里面，利用数组查下标很方便的特性
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }
        int n = arr.size();
        for(int i=0; i<n/2; i++)
        {
            if(arr[i]!=arr[n-1-i])
            {
                return false;
            }
        }
        return true;
    }
};

// 还可以利用反转链表，不额外占用空间