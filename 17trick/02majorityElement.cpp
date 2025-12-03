// 哈希很好做嘛
// 但是空间也要O(1)？
// 排序！！！不管众数具体是几，只要保证了众数的个数大于一半，那么一半处绝对是众数！
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};


// 随机：这个方法很有意思，因为按最差情况 只占一半 来算：
// 期望随机两次就能找到主元素，复杂度为 O(2n) < O(nlogn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums)
                if (num == candidate)
                    ++count;
            if (count > nums.size() / 2)
                return candidate;
        }
        return -1;
    }
};