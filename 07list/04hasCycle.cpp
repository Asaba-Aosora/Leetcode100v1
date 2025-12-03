/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 先来哈希暴力解法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            if(nodes.find(cur)==nodes.end())
            {
                nodes.insert(cur);
                cur = cur->next;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};


// 快慢指针：跑得快的一定会把跑得慢的套圈
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==0)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=slow)
        {
            if(fast==0 || fast->next==0)     // fast一定比slow先到终点，所以不用判slow
            {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};