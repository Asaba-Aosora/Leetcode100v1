// 三数之和, 实际上可以通过排序+双指针简化
// 排序, 遍历x1, 然后左右指针向中间靠拢
// 当然还要注意跳过重复值
// 小心越界！！！
using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++)  // 遍历x1
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int left = i+1, right = nums.size()-1;
            while(left<right)
            {
                int tmpAns=nums[i]+nums[left]+nums[right];
                if(tmpAns==0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    int tmpLeft = left+1; 
                    while(tmpLeft<right && nums[tmpLeft]==nums[left])
                    {
                        tmpLeft++;
                    }
                    left=tmpLeft;
                }
                else if(tmpAns<0)
                {                    
                    int tmpLeft = left+1; 
                    while(tmpLeft<right && nums[tmpLeft]==nums[left])
                    {
                        tmpLeft++;
                    }
                    left=tmpLeft;
                }
                else
                {
                    int tmpRight = right-1;
                    while(tmpRight>left && nums[tmpRight]==nums[right])
                    {
                        tmpRight--;
                    }
                    right=tmpRight;
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution slt;
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> ans = slt.threeSum(nums);
    for(int i=0; i<ans.size(); i++)
    {
        for(int num : ans[i])
        {
            cout << num << ' ';
        }
        cout <<endl;
    }
    return 0;
}