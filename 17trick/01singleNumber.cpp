// 遍历一次很简单，空间复杂度也要O(1)？

// 异或！！a^0 = a, a^a =0, a^b^a = a^a^b = b

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int flag = 0;
        for(int num : nums)
        {
            flag ^= num;
        }
        return flag;
    }
};