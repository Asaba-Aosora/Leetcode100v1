// 核心思想：找到左边一个小值和右边一个大值进行交换，能得到一个更大的序列
// 如何保证是“下一个”？
// 左边尽可能往右靠，右边值尽可能小
// 则左边的是，从右数“第一个”下降的值，右边则是从右数第一个比左值大的值
// 交换后，让左边数往右的所有数都排成升序。而本来右边都是降序，所以只要反转一下就ok

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int left = n-1;
        while(left--)
        {
            if(nums[left]<nums[left+1]) break;
        }
        if(left<0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int right = n-1;
        while(right>left)
        {
            if(nums[right]>nums[left])  break;
            right--;
        }
        swap(nums[left], nums[right]);
        reverse(nums.begin()+left+1, nums.end());

    }
};