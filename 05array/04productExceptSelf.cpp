class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 左数之积 * 右数之积 == ans
        int n = nums.size();
        vector<int> ans(n), left(n), right(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1] * nums[i-1];
            right[n-1-i] = right[n-i] * nums[n-i];
        }

        for(int i=0; i<n; i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};