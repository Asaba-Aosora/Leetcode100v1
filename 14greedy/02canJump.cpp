#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int maxD = 0;
        for(int i=0; i<len; i++)
        {
            // 遍历, 算最远可到的距离, 但是排除到不了下一个的情况
            maxD = max(maxD, i+nums[i]);
            if(maxD < i+1)
            {
                break;
            }
        }
        return (maxD >= len-1)? true: false;
    }
};

int main()
{
    Solution slt;
    vector<int> nums = {2,3,1,1,4};
    bool ans = slt.canJump(nums);
    cout << ans << endl;

    return 0;
}