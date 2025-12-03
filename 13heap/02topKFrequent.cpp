using namespace std;
// 桶计数？遍历一次就是n，分到各桶内。然后对桶进行排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;    // 存每个值在数组中的下标
        vector<pair<int,int>> buckets;
        vector<int> ans;
        // 放进桶里
        for(int num : nums)
        {
            if(hash.count(num))
            {
                buckets[hash[num]].second++;
            }
            else
            {
                hash.insert({num, buckets.size()});
                buckets.push_back({num,1});
            }
        }
        sort(buckets.begin(), buckets.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;
        });

        for(int i=0; i<k; i++)
        {
            ans.push_back(buckets[i].first);
        }
        return ans;
    }
};

// 手搓一个堆排序看看
// 其实用封装好的优先队列就ok了
class Solution {
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;     // 返回true说明a应该放下面
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 还是一样的先计数
        unordered_map<int,int> buckets;
        for(int& num : nums)
        {
            buckets[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> pq(cmp);    // 这里要传入比较函数作为参数！！
        for(auto& [key, value] : buckets)
        {
            if(pq.size()==k)
            {
                if(pq.top().second<value)
                {
                    pq.pop();
                    pq.emplace(key, value);
                }
            }
            else
            {
                pq.emplace(key, value);
            }
        }

        vector<int> ans;
        while(!pq.empty())
        {
            auto tmp = pq.top();
            pq.pop();
            ans.push_back(tmp.first);
        }
        return ans;
    }
};
