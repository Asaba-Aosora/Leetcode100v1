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

// 才发现没有单独的头节点()
// 我这个方法适合有头节点的链表结构，不过也可以试试标答的直接反转
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* newHead = new ListNode;
//         ListNode* tmpHead = new ListNode;
//         tmpHead->next = head;
//         head = tmpHead;     // 加一个头节点，不然太难做了
//         while(head->next != NULL)
//         {
//             ListNode* tmp = head->next;
//             head->next = head->next->next;
//             tmp->next = newHead->next;
//             newHead->next = tmp;
//         }
//         ListNode* tmp = newHead->next;
//         newHead->next = NULL;
//         delete newHead;
//         head = tmpHead->next;
//         tmpHead->next = NULL;
//         delete tmpHead;
//         return tmp;
//     }
// };


// 标答做法：直接反转（因为没有独立头节点）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};

// 不知道为啥报错，按理来说逻辑一致啊
// 总不能是next的问题吧
// 尝试访问一块被释放的内存
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        if(cur==0)
        {
            return cur;
        }
        ListNode* next = head->next;
        cur->next = 0;      // 这个cur之后要变成末尾，其next应该为nullptr，要置空！
        while(next!=0)
        {
            ListNode* tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }
};