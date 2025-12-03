/*
    接雨水, 主要思路就是遍历"积分", 对每一根柱子, 求其左右最高, 可得此柱子的积水高度
    dp可以基本实现, 然后用单调栈, 双指针优化
    我先写一版能跑的
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// // dp: 一条一条地填
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int len = height.size();
//         vector<int> leftMax(len);       // 第i个元素左边最高, 动态规划
//         vector<int> rightMax(len);
//         // 初始化dp表
//         leftMax[0]=0;
//         rightMax[len-1]=0;
//         for(int i=1; i<len; i++)
//         {
//             leftMax[i] = max(leftMax[i-1], height[i-1]);
//             rightMax[len-i-1] = max(rightMax[len-i], height[len-i]);
//         }

//         // 开始计算
//         int ans = 0;
//         for(int i=0; i<len; i++)
//         {
//             int h = min(leftMax[i], rightMax[i]);
//             if(h>height[i])
//             {
//                 ans += (h-height[i]);
//             }
//         }
//         return ans;
//     }
// };

// 单调栈: 一层一层地填
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         stack<int> stk;
//         int len = height.size();
//         int ans = 0;
//         for(int i=0; i<len; i++)
//         {
//             if(!stk.empty())
//             {                
//                 while(!stk.empty() && height[stk.top()]<height[i])      // 一开始这里写的是if, 后来发现单调栈出栈的每一个元素都得这么来一回, 所以改成while了
//                 {
//                     int top = stk.top();
//                     stk.pop();
//                     if(!stk.empty())
//                     {
//                         int left = stk.top();
//                         ans += (i-left-1)*(min(height[i], height[left])-height[top]);   // height[top]以下的已经被填平了
//                     }
//                 }
//             }
//             stk.push(i);
//         }
//         return ans;
//     }
// };

// 法三: 双指针, 节省空间. 一条一条地填, 左右指针指向的则是当前填的一条
/*
    双指针法整体的理解是：假设所有位置中有一个最大值，那么最大值左边的位置计算时取的一定是该位置左侧最大值，最大值右边的位置一定取的该位置右侧最大值，双指针法则是左右分别逼近，当碰到可能的最大值时，那个碰到的指针保持不动，另一个指针继续缩进。
    所以! 如果有 height[left]<height[right], 不要怀疑, right指向的就是全局最大值: 
    right可能是:
        -> 保持不动的rightMax: 比之前移动的leftMax大, 也比现在的height[left]大, 即当前的leftMax = min(rightMax, leftMax)
        -> 移动后的right: leftMax>之前的rightMax, 保持left不变, 但是移动right后找到了更大的height, 有height[right]>height[left]=leftMax, 即当前的leftMax = min(rightMax, leftMax)
    

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int leftmax = height[left], rightmax = height[right];
        int ans = 0;
        while(left < right)
        {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if(height[left] < height[right])
            {
                ans += leftmax - height[left];
                left++;
            }
            else
            {
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution slt;
    int ans = slt.trap(height);
    cout << ans << endl;

    return 0;
}
