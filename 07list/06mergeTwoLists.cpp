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

// 往一条链表上合并，不要跳来跳去的 
// ListNode* preHead = new ListNode(-1);
// 可以直接新建一个头节点！就不用单独处理prev==nullptr的情况了
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 都往list1上合并
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* prev1 = nullptr;

        if(cur1 == nullptr)
        {
            return list2;
        }
        if(cur2 == nullptr)
        {
            return list1;
        }

        // 此后的都是list1, list2为非空链表，保证return的逻辑没问题
        while(cur1!=nullptr && cur2!=nullptr)
        {
            if(cur1->val<cur2->val)
            {
                cur1 = cur1->next;
                if(prev1==nullptr)
                {
                    prev1 = list1;
                }
                else
                {
                    prev1 = prev1->next;
                }
            }
            else
            {
                // prev1 <= cur2 <= cur1  (->val)
                ListNode* tmp = cur2;
                cur2 = cur2->next;
                tmp->next = cur1;
                if(prev1==nullptr)
                {
                    prev1 = tmp;
                }
                else
                {
                    prev1->next = tmp;
                    prev1 = prev1->next;
                }
                // 由list2非减保证prev1 <= cur2
            }
        }

        if(cur1==nullptr && cur2!=nullptr)
        {
            prev1->next = cur2;
        }

        return list1->val<list2->val ? list1 : list2;
    }
};