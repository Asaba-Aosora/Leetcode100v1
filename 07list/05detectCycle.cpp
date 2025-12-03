/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 哈希肯定很好做
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            if(nodes.find(cur)!=nodes.end())
            {
                return cur;
            }
            nodes.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};

// 很nb！很nb的做法：快慢指针
// 当fast落后于slow距离为n时，只需n步就能追上，而n<=(b+c)，所以slow只走n步，就不会多走一圈
// 设交点到相遇点距离为b
// 此时有 fast.s = a + n(b+c) + b == 2*slow.s = 2*(a+b)
// 即有 a == (n-1)*(b+c)+c
// 此时slow在b处，b+a == n*(b+c) 回到交点，而从起点来的指针也走过a，来到交点
// 时间复杂度比哈希做法稍高，但是空间复杂度为O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr)
        {
            if(fast->next==nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                break;
            }
        }
        if(fast==nullptr)
        {
            return nullptr;
        }
        ListNode* cur = head;
        while(cur!=slow)
        {
            cur = cur->next;
            slow = slow->next;
        }
        return cur;
    }
};