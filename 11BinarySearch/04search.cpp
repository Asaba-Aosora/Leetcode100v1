// 搜索旋转排序数组
// 严格升序的数组, 向左挪了k位
// 两次二分?
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先找到左移的位数
        int n = nums.size();
        int l = 0, r = n-1;
        while(l!=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>=nums[l])
            {
                // l 和 mid 在同一个递增序列里(可能是前, 可能是后)
                // 注意可能有 l==mid 的情况! 所以要取等
                if(nums[mid]>nums[r])   l = mid+1;
                else    r = mid;
            }
            else
            {
                // r 和 mid 在同一个(且一定是后一个)递增序列里
                r = mid;
            }
        }
        // 此时 l==r==k
        int k = l;
        // 模运算, 变回原递增数组
        // 懒得模运算了, 直接新数组吧
        vector<int> newNums;
        newNums.insert(newNums.end(), nums.begin()+k, nums.end()); 
        newNums.insert(newNums.end(), nums.begin(), nums.begin()+k);
        l=0, r=n;
        while(l!=r)
        {
            int mid = (l+r)/2;
            if(newNums[mid]==target)
            {
                return (mid+k)%n;
            }
            else if(newNums[mid]<target)
            {
                l = mid+1;
                continue;
            }
            else
            {
                r = mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution slt;
    vector<int> nums = {3,1};
    int target = 3;
    cout << slt.search(nums, target);

    return 0;
}