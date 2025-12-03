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

// 法一：递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==0 || head->next==0)
        {
            return head;
        }

        ListNode* next = head->next;
        ListNode* nexthead = next->next;
        next->next = head;
        head->next = swapPairs(nexthead);

        return next;

    }
};

// 法二：迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode newhead(0, head);
        ListNode* prev = &newhead;
        ListNode* cur = prev->next;

        while(cur!=0)
        {
            if(cur->next==0)
            {
                break;
            }

            ListNode* nexthead = cur->next->next;
            prev->next = cur->next;
            prev->next->next = cur;
            cur->next = nexthead;

            prev = cur;
            cur = cur->next;
        }

        return newhead.next;
    }
};