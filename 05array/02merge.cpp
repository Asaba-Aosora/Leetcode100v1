// 我想排序但是题目没给 ！= 没有办法。可以自己排序！！sort+自己写得cmp函数
#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // 保证左边界递增，只需比较左边界和上一个右边界即可判定是否有重叠
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        
        int l = intervals[0][0];
        int r = intervals[0][1];

        for(auto tmp: intervals)
        {
            int tmpl = tmp[0];
            int tmpr = tmp[1];

            // 无重叠
            if(tmpl > r)
            {
                ans.push_back({l, r});
                l = tmpl;
                r = tmpr;
            }
            else
            {
                // 扩大了范围
                if(tmpr > r)
                {
                    r = tmpr;
                }
            }
        }
        ans.push_back({l, r});      // 记住最后一次要单独加进来
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = [[1,3],[2,6],[8,10],[15,18]];



    return 0;
}