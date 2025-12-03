// unordered_set: 集合, 唯一性, 无序, 基于哈希表实现
// O(n)的算法: 遍历n*查找1, 所以一次遍历内要解决
// 以x-1为起始的序列总比以x为起始的序列长, 且要求连续, 所以无x-1时必定是断开的两个序列
// 只需要返回长度, 所以不需要管具体是啥
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0; i<nums.size(); i++)
        {
            set.insert(nums[i]);    // 不是push, 是insert
        }
        
        // 不用这种写法, 因为set本身无序, 直接范围内遍历会好很多
        // for(auto it = set.begin(); it != set.end(); it++)
        // {
        //     int tmp = it->
        // }

        int longest = 0;
        for(const int& num : set)
        {
            if(!set.count(num-1))     // count返回0: 未找到; 返回1: 找到
            {
                int currentNum = num;
                int len = 1;
                while(set.count(currentNum+1))
                {
                    currentNum++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};