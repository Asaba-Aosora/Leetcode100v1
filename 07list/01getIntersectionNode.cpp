#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
// 先无脑用哈希做一次
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> anodes;
//         ListNode* tmpA = headA;
//         while(tmpA != NULL)
//         {
//             anodes.insert(tmpA);
//             tmpA = tmpA->next;
//         }
//         ListNode* tmpB = headB;
//         while(tmpB != NULL)
//         {
//             if(anodes.find(tmpB) != anodes.end())
//             {
//                 return tmpB;
//             }
//             tmpB = tmpB->next;
//         }
//         return NULL;
//     }
// };

// 双指针法：利用 a+n+b(+n) == b+n+a(+n) 来找第一个相交点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        bool flag = false;      // A经过NULL变成B的标志（现在为false）当tmpA再次为NULL时，说明无焦点
        while(tmpA != tmpB)
        {
            if(tmpA == NULL)
            {
                if(flag == true)
                {
                    return NULL;
                }
                tmpA = headB;
            }
            else
            {
                tmpA = tmpA->next;
            }

            if(tmpB == NULL)
            {
                tmpB = headA;
            }
            else
            {
                tmpB = tmpB->next;
            }

        }
        return tmpA;
    }
};

