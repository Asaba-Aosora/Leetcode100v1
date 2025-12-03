#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check()
    {
        for(auto p: ori)
        {
            if(p.second > cnt[p.first])
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        // 初始化ori的字母频数
        for(char ch: t)
        {
            ori[ch]++;
        }
        int l=0, r=-1;
        int ansL=-1, len=INT_MAX;

        while(r<int(s.size()))
        {
            // r右移
            r++;
            if(ori.find(s[r]) != ori.end())    // string以\0结尾，不会因为r=s.size()越界
            {
                // 要在t中存在，才有研究意义，才需要添加进cnt
                cnt[s[r]]++;
            }

            // 检查是否已经涵盖，并尝试把左指针右移
            while(l<s.size() && check())
            {
                //如果能进入到这一步，说明已经符合要求了，可以开始迭代ans了
                if(r-l+1 < len)
                {
                    ansL=l;
                    len=r-l+1;
                }
                if(cnt.find(s[l]) != cnt.end())
                {
                    cnt[s[l]]--;
                }
                l++;
            }

        }
        return ansL==-1? string() : s.substr(ansL, len);
    }
};

// 优化的方法的确是用diff！不过这里只统计小于，所以改成叫less，可以把比较的时间优化到O(1)


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution slt;
    cout << slt.minWindow(s, t);

    return 0;
}