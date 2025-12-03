#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;


// 靠，不是求和，是求窗口中的最大值
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int tmp=0;
//         int len=nums.size();
//         vector<int> ans;
//         int maxn=INT_MIN;
//         // 初始化
//         for(int i=0; i<k; i++)
//         {
//             tmp+=nums[i];
//         }
//         maxn=max(maxn, tmp);
//         ans.push_back(maxn);
//         for(int lp=1; lp<len-k+1; lp++)
//         {
//             tmp-=nums[lp-1];
//             tmp+=nums[lp+k-1];
//             maxn=max(maxn, tmp);
//             ans.push_back(maxn);
//         }
//         return ans;
//     }
// };

// 用大顶堆试一试
// 堆里面存pair对，要存最大值及其下标。当最大值被移出边界时，就弹出、继续判断边界
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int len = nums.size();
//         vector<int> ans;
//         priority_queue<pair<int, int>> heap;    // <nums[i], i>。且pair的排序规则是先比first的大小，再比second的大小
//         for(int i=0; i<k; i++)
//         {
//             heap.emplace(nums[i], i);   // 用emplace，原地构造直接传入。而push需要先构造再传入，多一个操作。
//             // push用pq.push(pair<int, int>(1, 2)); 或 pq.push({3, 4});
//         }

//         for(int lp=0; lp<len-k+1; lp++)
//         {
//             auto tmp = heap.top();
//             ans.push_back(tmp.first);

//             // 处理下一步右移的逻辑
//             while(tmp.second<lp+1)
//             {
//                 heap.pop();
//                 if(heap.empty())
//                 {
//                     break;
//                 }
//                 tmp=heap.top();
//             }
//             if(lp+k<len)
//             {heap.emplace(nums[lp+k], lp+k);}
//         }
//         return ans;
//     }
// };

// 单调队列。维护一个单调递减的队列。注意！存nums的下标，再查询值，方便维护边界
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int len=nums.size();
//         deque<int> dq;
//         vector<int> ans;
//         for(int i=0; i<k; i++)
//         {
//             // 初始化dq
//             while(!dq.empty() && nums[dq.back()]<nums[i])
//             {
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }
//         ans.push_back(nums[dq.front()]);

//         for(int i=k; i<len; i++)
//         {
//             while(!dq.empty() && dq.front()<i-k+1)
//             {
//                 dq.pop_front();
//             }
//             while(!dq.empty() && nums[dq.back()]<nums[i])
//             {
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//             ans.push_back(nums[dq.front()]);
//         }

//         return ans;
//     }
// };

// 分块预处理。一个窗口只能有两种状态：刚好在一个组内 or 横跨相邻的两个组
// 维护前缀最大值和后缀最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();
        vector<int> prefix(len), suffix(len);

        // 初始化
        for(int i=0; i<len; i++)
        {
            if(i%k==0)
            {
                prefix[i] = nums[i];
            }
            else
            {
                prefix[i] = max(prefix[i-1], nums[i]);
            }
        }
        for(int i=len-1; i>-1; i--)
        {
            if(i==(len-1) || (i+1)%k==0)
            {
                // i是最后一格 or i的右边是下一组开始（即i是上一组结尾）
                suffix[i] = nums[i];
            }
            else
            {
                suffix[i] = max(suffix[i+1], nums[i]);
            }
        }

        // 根据分组来提取结果。注意，在同一组时 suffix[0] == prefix[k-1], 所以可以直接合并进max()
        for(int i=0; i<len-k+1; i++)
        {
            ans.push_back(max(suffix[i], prefix[i+k-1]));
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1,-1};
    int k = 1;
    Solution slt;
    vector<int> ans = slt.maxSlidingWindow(nums, k);

    for(int i: ans)
    {
        cout << i << " ";
    }

    return 0;
}