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

// 注意观察数据结构
// 法一：归并，两两合并
class Solution {
    ListNode* merge(ListNode* h1, ListNode* h2)
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
                prev->next =c2;
                c2 = c2->next;
                prev = prev->next;
            }
        }
        c1 ? prev->next = c1 : prev->next = c2;
        return hair.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        for(int step=1; step<len; step*=2)
        {
            for(int i=0; i<len && i+step<len; i+=2*step)    // 防止越界！！i<len && **i+step<len**
            {
                lists[i] = merge(lists[i], lists[i+step]);
            }
        }
        return lists.empty() ? nullptr : lists[0]; 
    }
};

// 法二：最小堆。为什么可行？因为是链表，天然带了next
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 自定义cmp，试试用labmda函数写
        // 优先队列的cmp和sort不一样，这个是 "返回true == 优先级更低"
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;     // cmp应该作为一个类型传入，如果写的是函数，就要转化。不然就写结构体，struct cmp，重载 "()" 运算符
        int len = lists.size();
        for(int i=0; i<len; i++)
        {
            // 在这里就存非空，排除空指针影响
            if(!lists[i])
            {
                continue;
            }
            pq.push(lists[i]);
        }

        ListNode hair;
        ListNode* prev = &hair;

        while(!pq.empty())
        {
            ListNode* top = pq.top();
            pq.pop();
            prev->next = top;
            prev = prev->next;
            if(top && top->next)
            {
                pq.push(top->next);
            }
        }

        return hair.next;

    }
};