// 这道题双指针, 一左一右, 往中间靠拢, 谁小动谁. 思路简单, 但是数学证明严谨
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxV=0;
        while(left!=right)
        {
            int curV = min(height[left], height[right])*(right-left);
            maxV = max(curV, maxV);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxV;
    }
};