#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rp = -1;    // right pointer
        int max_len = 0;
        int cur_len = 0;
        unordered_set<char> occ;    // occurred charactors，用set不用map，因为只需要找存在性，不需要找对应的键值
        for(int lp = 0; lp < s.size(); lp++)
        {
            if(lp!=0)
            {
                occ.erase(s[lp-1]);
                cur_len -= 1;
            }
            while(rp+1<s.size() && occ.find(s[rp+1]) == occ.end())   // 找不到，说明未重复，且要注意不能越界
            {
                rp++;
                cur_len++;
                occ.insert(s[rp]);
            }
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};

int main ()
{
    Solution slt;
    string str = "bbbbb";
    cout << slt.lengthOfLongestSubstring(str);

    return 0;
}