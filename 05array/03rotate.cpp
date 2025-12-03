// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         // 其实就是个模运算。原地解决的话，只需要“循环”
//         int i = 0;
//         int n = nums.size();
//         int tmp = nums[i];

//         // 有个缺陷：n % k == 0 时，不是一次遍历就ok的，必须遍历 i=0...k-1
//         while(1)
//         {
//             i = (i+k) % n;
//             swap(tmp, nums[i]);
//             if(i==0)
//             {
//                 break;
//             }
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[(i+k)%n] = nums[i];
        }
        copy(ans.begin(), ans.end(), nums.begin());
    }
};