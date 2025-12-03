// 这个题我取巧了, 最后才把nums赋为ans
// 其实用"交换"就很好, 左指针指处理好的队尾, 右指针指待处理的队头, 符合条件时直接交换
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int> ans;    // 先只存nums里的非零元素
//         int cnt=0;      // 计0的个数
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i]==0)
//             {
//                 cnt++;
//             }
//             else
//             {
//                 ans.push_back(nums[i]);
//             }
//         }

//         for(int i=0; i<cnt; i++)
//         {
//             ans.push_back(0);
//         }
//         nums=ans;
//     }
// };

// 用交换代替移动位置, 妙. 交换是O(1), 移动位置是O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int right=0;
        int len=nums.size();
        for(int i=0; i<len; i++)
        {
            if(nums[right]!=0)
            {
                swap(nums[right], nums[left]);
                left++;
                right++;
            }
            else
            {
                right++;
            }
        }
    }
};