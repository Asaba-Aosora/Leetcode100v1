#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int end=0;
        int cnt=0;
        int maxPos=0;
        int n=nums.size();

        for(int i=0; i<n-1; i++)    // i<n-1 而非 i<n, 因为如果已经到 n-1 了, 可能正好 n-1 是上个end, 这时候就会多跳一次, 如 nums[0]=2, size=1 的情况
        {
            if(i<=maxPos)
            {
                maxPos = max(maxPos, i+nums[i]);
                // if(i>end)
                if(i==end)  // 为什么不能写"i>end"? 因为此时不更新右界就无法向右跳
                {
                    end = maxPos;
                    cnt++;
                }
            }
            // if(maxPos>=n-1)
            // {
            //     cnt++;      // 如果要提前退出, 必须要加一步! 因为此时没有触发上一个i==end的cnt++, 上一个区域还未遍历完, 但是到这里已经多加了一步
            //     break;      // 上述其实不对, 若 nums[0]=2, size=1, 那么也不需要跳, 但是如果这里cnt++的话就会多算一次
            // }
        }
        return cnt;
    }
};

int main()
{
    Solution slt;
    vector<int> nums = {0};
    cout << slt.jump(nums) << endl;

    return 0;
}