// 非递减(即非严格递增), 找target在nums的开始和结束位置
// 二分, but不是一般的二分

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int n;
    int ansl, ansr;
    void binarySearch(vector<int>& nums, int target, int l, int r)
    {
        if(l==r)    return;
        // 针对传入的区间进行二分, 并更新 ansl, ansr
        int mid = (l+r)/2;
        if(nums[mid]==target)
        {
            if(mid<ansl)
            {
                ansl = mid;
                // 继续往左找能不能有更小的l
                binarySearch(nums, target, l, mid);
            }
            if(mid>ansr)
            {
                ansr = mid;
                binarySearch(nums, target, mid+1, r);
            }
        }
        else if(nums[mid]<target)
        {
            binarySearch(nums, target, mid+1, r);
        }
        else
        {
            binarySearch(nums, target, l, mid);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums.size();
        int l=0, r=n;
        ansl = n, ansr = -1;
        binarySearch(nums, target, l, r);
        return ansr==-1? vector<int>{-1, -1} : vector<int>{ansl, ansr};
    }
};

int main()
{
    Solution slt;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    auto ans = slt.searchRange(nums, target);
    for(auto n : ans)
    {
        cout << n << ' ';
    }

    return 0;
}