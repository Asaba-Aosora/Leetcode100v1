// 排序算法
// 但是 O(n) 很神奇, 一般是 O(nlogn) 啊
// 因为不用排序，只用选择！
// 分治，每次从 1/2 的区间里面找目标元素，每个区间内一次遍历
class Solution {
private:
    int quickSelect(vector<int>& nums, int k)
    {
        int pivot = nums[rand()%nums.size()];   // 太神秘了这个随机
        vector<int> greater, equal, less;
        for(int num : nums)
        {
            if(num>pivot)           greater.push_back(num);
            else if(num==pivot)    equal.push_back(num);
            else                    less.push_back(num);
        }
        // 然后找第k个在哪个区间即可
        if(k<=greater.size())
        {
            return quickSelect(greater, k);
        }
        else if(k>greater.size()+equal.size())
        {
            return quickSelect(less, k-greater.size()-equal.size());
        }
        else
            return pivot;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};