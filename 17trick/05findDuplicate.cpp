// 快慢指针法
// 用nums的(index,value)来建图，因为value必定在(1,n)中，也在nums的index范围内
// 所以从nums的任意点出发，都可以构建一条无限长的路径。而节点数有限，无限长必定是因为有环
// 环的起点则是重复的数字，可以用快慢指针来做

// 快慢指针一定要从0开始，因为要依靠前一节的链。而因为value没有0，所以可以保证0是一条链的开头
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[slow];
        // 先走一步，免得进不了循环
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // 相等时，把slow移回0
        slow = 0;
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};