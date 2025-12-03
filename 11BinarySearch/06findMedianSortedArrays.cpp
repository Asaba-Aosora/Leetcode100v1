// 两个有序数组的共同中位数
// 如果先合并, 再二分, 也很简单, 但是时间复杂度应该是 O(m+n), 达不到 O(log(m+n))
// 所以不合并直接二分? 
// 管得的, 我先打一版合并法
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         // 遍历合并新数组
//         vector<int> nums;
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int p1 = 0, p2 = 0;
//         while(p1<n1 && p2<n2)
//         {
//             if(nums1[p1]<nums2[p2])
//             {
//                 nums.push_back(nums1[p1]);
//                 p1++;
//             }
//             else
//             {
//                 nums.push_back(nums2[p2]);
//                 p2++;
//             }
//         }
//         if(p1==n1)
//         {
//             nums.insert(nums.end(), nums2.begin()+p2, nums2.end());
//         }
//         else
//         {
//             nums.insert(nums.end(), nums1.begin()+p2, nums1.end());
//         }

//         // 现在来中位数吧
//         if((n1+n2)%2==1)
//         {
//             int mid = (n1+n2)/2;
//             return nums[mid];
//         }
//         else
//         {
//             int mid = (n1+n2)/2;
//             return = (nums[mid]+nums[mid-1])/2.0;
//         }
//     }
// };

// 方法二: 把问题转化为 "找两个有序数组中的 第k小 的数"
// 每次排除k/2个一定当不了第k小的数, 在剩下的数组里求 第k/2小的数


// 方法三: 划分!
// 长为n的数组, 具有n+1个间隔, 可以划成n+1个数组
// 中位数: 把数组划分为 left_max <= right_max && (left_nums == right_nums || left_nums == right_nums-1)   (奇数时, 中位数划在右边)
// 两个数组的中位数类似, 也要找这么一个划分 -- 分别把两个数组, 用 i,j 进行划分
// 已知两数组长度之和确定, 即中位数划分下标之和确定, i+j 为定值, 即搜索i时可以直接推知j
// 那二分搜索i就好了, 时间复杂度为 O(log min(m,n))

// 左边 i+j == 右边 m-i + n-j (-1)  -- 2(i+j) == m+n(-1) 保持为偶数, 又整除时-1可以被消掉
// therefore i+j == (m+n)/2
// j = (m+n)/2 - i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n)
        {
            swap(nums1, nums2);
            swap(m, n);
        }
        // 保证nums1长度更短
        // 二分搜索i
        int l1 = 0, r1 = m;
        int i,j;
        double ans=0;
        while(l1<=r1)   // 可能是相等越界时！不能忽略！
        {
            // 注意要防止越界
            i = (l1+r1)/2;
            j = (m+n)/2 - i;

            int num_i = i<m ? nums1[i] : INT_MAX;
            int num_j = j<n ? nums2[j] : INT_MAX;
            int num_im1 = i>0 ? nums1[i-1] : INT_MIN;
            int num_jm1 = j>0 ? nums2[j-1] : INT_MIN;

            // 终止情况
            if(max(num_im1, num_jm1)<=min(num_i, num_j))
            {
                if((m+n)%2==0)
                {
                    // 为偶数, 则一前一后
                    ans = (max(num_im1, num_jm1)+min(num_i, num_j))/2.0;
                }
                else
                {
                    // 为奇数, 后一个
                    ans = min(num_i, num_j);
                }
                break;
            }
            else if(num_i<num_jm1)
            {
                // i小了, 往右移
                l1=i+1;
                continue;
            }
            else
            {
                // i大了, 左移
                r1=i;
                continue;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution slt;
    cout << slt.findMedianSortedArrays(nums1, nums2);

    return 0;
}