
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 递归居然没爆内存，太奇妙了
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* tmp = head;   // 用来找下一个head
//         for(int i=0; i<k; i++)
//         {
//             if(tmp==0)
//             {
//                 return head;
//             }
//             tmp = tmp->next;
//         }
//         // 现在tmp是newhead了

//         // 现在开始反转这一组的链表
//         ListNode dummy(0, head);
//         ListNode* prev = &dummy;
//         ListNode* cur = prev->next;
//         while(cur!=tmp)
//         {
//             ListNode* next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }
//         // 此时dummpy->next==head还是成立，但是head->next==dummpy，要改成下一个链表的头节点
//         head->next = reverseKGroup(tmp, k);

//         return prev;
//     }
// };

// 用迭代再做一次
class Solution {
public:
    pair<ListNode*, ListNode*> myreverse(ListNode* head, ListNode* tail)
    {
        if(head==tail)
        {
            return {head, tail};
        }
        ListNode* prev = head;
        ListNode* cur = prev->next;
        while(cur!=tail)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        // 注意！最后一个cur还没有连接到prev上
        tail->next = prev;
        // 现在head是newtail，tail是newhead了
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 这个函数的主要思想就是，prev->next = newhead, newtail->next = nexthead
        // newhead, newtail 的反转逻辑，可以另写一个函数，封装性更好
        ListNode hair(0, head);
        ListNode* prev = &hair;
        ListNode* curhead = prev->next;
        ListNode* tmp = prev;   // k==1时，tmp+=1, 正好变成tmp==curhead
        int cnt = 0;
        while(tmp)
        {
            if(cnt==k)
            {
                cnt=0;
                ListNode* nexthead = tmp->next;
                pair<ListNode*, ListNode*> result = myreverse(curhead, tmp);
                prev->next = result.first;
                result.second->next = nexthead;
                prev = result.second;
                curhead = prev->next;
                tmp = prev;
            }
            else
            {
                tmp = tmp->next;
                cnt++;
            }

        }

        return hair.next;

    }
};