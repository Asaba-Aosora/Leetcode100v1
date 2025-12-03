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

// 归并排序
// 其实就是 链表的中间节点 + 合并两个有序链表
    // 先写个自定义比较函数
    // cmp(a, b) 即判断"a是否应该在b的左边" ？ ture(在左边) ：false(在右边)
    // 升序：小的在左边，即 a<b 是返回true
    // 降序正好相反
    // 不过这里用不到啦
    // bool cmp(ListNode* a, ListNode* b)
    // {
    //     return a->val < b->val;
    // }

class Solution {
    // 找中间节点
    // 注意：要用prev，不然无法断开两个链表。不断开的话，就无法判断 tail==nullptr
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = nullptr;
        return slow;
    }

    // 合并两个有序链表
    ListNode* merge(ListNode* h1, ListNode* h2)
    {
        ListNode hair;
        ListNode* cur = &hair;

        ListNode* c1 = h1;
        ListNode* c2 = h2;

        while(c1 && c2)
        {
            if(c1->val < c2->val)
            {
                cur->next = c1;
                c1 = c1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = c2;
                c2 = c2->next;
                cur = cur->next;
            }
        }

        c1==nullptr ? cur->next=c2 : cur->next=c1;

        return hair.next;
    }

public:
    // 先写一版递归吧
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode* head2 = middleNode(head);
        // 分治，分别递归排序
        head = sortList(head);
        head2 = sortList(head2);
        
        // 再合并
        head = merge(head, head2);

        return head;
    }
};

// 迭代版本
class Solution {
    // 获取长度
    int getLength(ListNode* head)
    {
        int len = 0;
        ListNode* cur = head;
        while(cur)
        {
            len++;
            cur = cur->next;
        }
        return len;
    }

    // 分割链表
    ListNode* split(ListNode* head, int step)
    {
        if(head==0)
        {
            return head;
        }

        int cnt = 0;
        ListNode* cur = head;
        ListNode* prev = head;

        while(cur && cnt<step)
        {
            cnt++;
            prev = cur;
            cur = cur->next;
        }

        prev->next = 0;
        return cur;

    }

    // 合并两个有序链表
    pair<ListNode*, ListNode*> merge(ListNode* h1, ListNode* h2)
    {
        ListNode hair;
        ListNode* prev = &hair;
        ListNode* c1 = h1;
        ListNode* c2 = h2;
        while(c1 && c2)
        {
            if(c1->val < c2->val)
            {
                prev->next = c1;
                c1 = c1->next;
                prev = prev->next;
            }
            else
            {
                prev->next = c2;
                c2 = c2->next;
                prev = prev->next;
            }
        }

        c1==0 ? prev->next = c2 : prev->next = c1;
        ListNode* cur = prev->next;
        while(cur)
        {
            prev = cur;
            cur = cur->next;
        }


        return {hair.next, prev};
    }

public:
    ListNode* sortList(ListNode* head) {
        // 先获取链表长度
        int len = getLength(head);
        ListNode hair(0, head);

        // 然后逐步更新step，每个step内先拆分后合并
        // 每两个进行一次合并
        for(int step=1; step<len; step*=2)
        {
            // 先遍历step，对每个step都遍历、分割、合并一次
            ListNode* prev = &hair;     // 上一个链表的尾部，新head的上一个
            ListNode* cur = prev->next;     // 其实是新链表的头
            while(cur)
            {
                // 分割，得到下一个头
                ListNode* head1 = split(cur, step);
                ListNode* head2 = split(head1, step);   // 下一个cur，提前存下来

                // 合并
                auto [newhead, newtail] = merge(cur, head1);
                prev->next = newhead;
                cur = head2;
                prev = newtail;
            }
        }

        // 最后return
        return hair.next;
    }
};