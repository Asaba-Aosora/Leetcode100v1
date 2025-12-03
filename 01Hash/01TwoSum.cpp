/*
    两数之和，我的暴力枚举可以过。vector用push_back()搞忘了
*/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> answer;
//         for(int i=0; i<nums.size(); i++)
//         {
//             for(int j=i+1; j<nums.size(); j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     answer.push_back(i);
//                     answer.push_back(j);
//                     return answer;
//                 }
//             }
//         }
//         return answer;
//     }
// };

/*
    高端方法：哈希表
    "快速找到target-x", 把这里的复杂度从O(N)减至O(1)
    使用unordered_map(哈希表)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashTable;
        for(int i=0; i<nums.size(); i++)
        {
            auto it = hashTable.find(target-nums[i]);   // 迭代器
            if(it != hashTable.end())
            {
                return {it->second, i};
            }
            hashTable[nums[i]] = i;     // 把nums的值作为哈希表的键, nums的下标作为哈希表的值. 利用哈希表查询键的复杂度为O(1)
        }
        return {};
    }
};