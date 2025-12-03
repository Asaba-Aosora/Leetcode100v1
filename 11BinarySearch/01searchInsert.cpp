class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                right = mid;
                continue;
            }
            else
            {
                left = mid+1;
                continue;
            }
        }
        // 现在只是left==right了，但是最后一次没有判定
        if(nums[left]>=target)
        {
            return left;
        }
        else
        {
            return left+1;
        }
    }
};