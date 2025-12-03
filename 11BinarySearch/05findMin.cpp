// 右移n次的数组中, 查找最小值
// 感觉和上一个题无比像, 甚至还少几步
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1;
        while(l!=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>=nums[l])
            {
                if(nums[mid]>nums[r])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];
    }
};