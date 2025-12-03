class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i=0; i<n; i++)
        {
            set.insert(nums[i]);
        }
        for(int i=1; i<=n; i++)
        {
            if(set.find(i) == set.end())
            {
                return i;
            }
        }
        return n+1;
    }
};