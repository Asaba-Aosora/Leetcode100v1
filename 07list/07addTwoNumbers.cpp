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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode prevhead (0, l1);
        ListNode* prev = &prevhead;
        int in = 0;
        // 懒得重新分配了，直接把l1当成结果算了
        while(cur1!=nullptr && cur2!=nullptr)
        {
            int sum = cur1->val + cur2->val + in;
            cur1->val = sum%10;
            in = sum/10;
            cur1=cur1->next;
            cur2=cur2->next;
            prev=prev->next;
        }

        // 跟上个题不一样的是，这个有进位！不能直接接过去
        if(cur1==nullptr)
        {
            prev->next = cur2;
            while(cur2!=nullptr)
            {
                int sum = cur2->val + in;
                cur2->val = sum%10;
                in = sum/10;
                cur2 = cur2->next;
                prev = prev->next;
            }
        }
        else
        {
            while(cur1!=nullptr)
            {
                int sum = cur1->val + in;
                cur1->val = sum%10;
                in = sum/10;
                cur1 = cur1->next;
                prev = prev->next;
            }
        }

        if(in)
        {
            ListNode* tmp = new ListNode(in);
            prev->next = tmp;
        }
        
        return l1;

    }
};