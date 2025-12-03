#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p1 = 0;
        int n = nums.size();
        for(int p=0; p<n; p++)
        {
            if(nums[p]==0)
            {
                swap(nums[p], nums[p0]);
                if(nums[p]==1)
                {
                    swap(nums[p], nums[p1]);
                }
                p0++;
                p1++;
            }
            else if(nums[p]==1)
            {
                swap(nums[p], nums[p1]);
                p1++;
            }
        }
    }
};

int main()
{
    Solution slt;
    vector<int> nums = {2,0,2,1,1,0};
    slt.sortColors(nums);
    for(int num : nums)
    {
        cout << num << ' ';
    }

    return 0;
}