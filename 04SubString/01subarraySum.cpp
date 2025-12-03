#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 不对，题目要求有负数，不能用滑动窗口做。因为滑动窗口只考虑非负
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int ans=0;
//         int tmpsum=0;
//         int rp=-1;
//         int len=nums.size();    // unsign --> int
//         for(int lp=0; lp<len; lp++)
//         {
//             // 反正都要遍历lp，for里面就不需要加速lp右移了
//             if(lp!=0)
//             {
//                 tmpsum-=nums[lp];
//                 lp++;
//             }
//             while(tmpsum<k)
//             {
//                 rp++;
//                 tmpsum+=nums[rp];
//             }
//             // 手动把长度为负的rp往右移
//             if(rp<lp)
//             {
//                 rp++;
//                 tmpsum+=nums[rp];
//             }

//             if(tmpsum==k)
//             {
//                 ans++;
//             }

//         }


//         return ans;
//     }
// };

// 暴力枚举，要时间超限
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int ans=0;
        
//         for(int rp=0; rp<nums.size(); rp++)
//         {
//             int tmpsum=0;
//             for(int lp=rp; lp>=0; lp--)
//             {
//                 tmpsum+=nums[lp];
//                 if(tmpsum==k)
//                 {
//                     ans++;
//                 }
//             }
//         }

//         return ans;
//     }
// };

// 用前缀和来做。sum[i]就是从0到i的和，要求m~n的和为k，即求sum[n]-sum[m-1]==k
// 用哈希表可以表示截至到i，前面每种和有多少
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int len = nums.size();
        int ans=0;
        vector<int> sum(len+1);
        sum[0]=0;   // sum[0]是没有元素！但是还是要额外处理没有元素的情况
        hash[0]++;

        for(int i=0; i<len; i++)
        {
            sum[i+1] = sum[i] + nums[i];
            hash[sum[i+1]]++;

            int cnt = hash[sum[i+1]-k];
            if(k==0 && cnt>0)
            {
                cnt--;
            }
            ans+=cnt;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1};
    int k = 0;
    Solution slt;
    int ans = slt.subarraySum(nums, k);
    cout << ans;

    return 0;
}
