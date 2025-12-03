/*
    用排序后的str来当哈希表的键, ans里的下标为哈希表的值
    快排是O(klogk), 查询时间O(1), 遍历表是O(n), 总时间复杂度是O(n*klogk)
    n< 1e4, k<100
*/

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         unordered_map<string, int> hashtable;
//         for(int i=0; i<strs.size(); i++)
//         {
//             string tmp = strs[i];
//             sort(tmp.begin(), tmp.end());
//             auto it = hashtable.find(tmp);
//             if(it != hashtable.end())
//             {
//                 ans[it->second].push_back(strs[i]);
//             }
//             else
//             {
//                 hashtable[tmp] = ans.size();
//                 ans.push_back({strs[i]});
//             }
//         }
//         return ans;
//     }
// };

/*
    第二种做法是计数
    涉及位图, 需要手搓, 所以要lambda函数: [capture](parameters) -> return_type { body }
    这个方法有点狠
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 先写一个得到位图的函数(作为hash表的键)
        // fn: 函数对象; array: 数组, 存int, 长26; 返回值: 位图, 用无符号整数表示
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26> &arr) -> size_t
        {
            // accumulate调用的二元函数, 第一个参数默认是累计值acc, 第二个参数是迭代器当前指向的元素
            // 初值用无符号整数0, 写作0u
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num){
                return (acc<<1)^fn(num);
            });
        };

        // unordered_map, 第一个参数为键, 第二个参数为值, 第三个参数为哈希(的类型). 使用第三个参数时, 需传入自定义哈希函数的实例, 为了显式表现自定义, 初始桶数量可设为0
        // decltype: 获取类型
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);

        for(string& str: strs)
        {
            array<int, 26> counts{};
            int len = str.size();
            for(int i=0; i<len; i++)
            {
                counts[str[i]-'a']++;
            }
            mp[counts].emplace_back(str);
            // mp[counts]: 有这个键则返回它的iterator, 若没有这个键, 则创建并返回
            // emplace_back: 在末尾创建对象
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};