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

// 法一：遍历求长度，再遍历一次
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* tmp = head;
        if(head==0)
        {
            return head;
        }
        while(tmp!=0)
        {
            len++;
            tmp = tmp->next;
        }
        int cnt = len-n-1;
        tmp = head;
        while(cnt>0)    // 注意，len-len-1是负的，要用>0来判断
        {
            tmp = tmp->next;
            cnt--;
        }
        // 现在tmp指向被删节点的前一个。如果 n == len 的话，那tmp还是head
        if(len == n)
        {
            tmp = tmp->next;
            head->next = 0;
            delete head;
            return tmp;
        }
        
        // 现在确保tmp是被删的前一个了
        ListNode* cur = tmp->next;
        tmp->next = cur->next;
        cur->next = 0;
        delete cur;

        return head;
    }
};


// 法二：栈！想出来这个的真的是天才，利用FILO的特性，直接倒序了
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> stk;
        ListNode* cur = head;
        while(cur!=0)
        {
            stk.push(cur);
            cur = cur->next;
        }
        ListNode newhead;
        int cnt = 0;
        while(!stk.empty())
        {
            cnt++;
            if(cnt==n)
            {
                stk.pop();
                continue;
            }
            ListNode* tmp = stk.top();
            stk.pop();
            tmp->next = newhead.next;
            newhead.next = tmp;
        }
        return newhead.next;
    }
};

// 快慢指针：fast超前slow n个节点，当fast到终点时，slow在被删除的节点
// fast到len时，slow到了len-n-1，这样slow的下一个才好被删除
// 为防止n=len时slow为-1，添加哑节点作为头节点
// 相当于是fast到n时，slow从-1开始出发
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode newhead(0, head);
        ListNode* fast = head;
        for(int i=0; i<n; i++)
        {
            fast = fast->next;
        }
        // 现在fast在n处，slow在-1处
        // 为什么slow不从0开始？防止删除0元素
        ListNode* slow = &newhead;
        while(fast!=0)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 此时删除slow的下一个
        ListNode* cur = slow->next;
        slow->next = cur->next;
        cur->next = 0;
        delete cur;

        return newhead.next;
    }
};