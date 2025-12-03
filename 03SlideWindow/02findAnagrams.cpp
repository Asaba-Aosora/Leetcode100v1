// 固定长度的滑动窗口！直接把p的长度设为窗口长度，就可以只维护各字母数量了
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// // 这是基础版滑动窗口，每次都需要比较p和s
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         vector<int> scnt(26);
//         vector<int> pcnt(26);
//         int plen = p.size();

//         if(s.size()<p.size())
//         {
//             return ans;
//         }

//         for(int i=0; i<plen; i++)
//         {
//             pcnt[p[i]-'a']++;
//             scnt[s[i]-'a']++;
//         }

//         for(int lp=0; lp<s.size()-plen+1; lp++)
//         {
//             if(lp!=0)
//             {
//                 scnt[s[lp-1]-'a']--;
//                 scnt[s[lp+plen-1]-'a']++;
//             }

//             if(scnt==pcnt)
//             {
//                 ans.push_back(lp);
//             }
//         }

//         return ans;
//     }
// };

// 试一试只比较差值
// 这一版实际上还是复杂度没降低，真正降复杂度要用int differ
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         vector<int> differ(26);
//         int plen = p.size();
//         int slen = s.size();

//         if(slen<plen)
//         {
//             return ans;
//         }

//         // 以p为基准，s中多了为正、少了为负
//         for(int i=0; i<plen; i++)
//         {
//             differ[s[i]-'a']++;
//             differ[p[i]-'a']--;
//         }

//         for(int lp=0; lp<slen-plen+1; lp++)
//         {
//             if(lp!=0)
//             {
//                 differ[s[lp-1]-'a']--;
//                 differ[s[lp+plen-1]-'a']++;
//             }

//             bool is_diff = false;
//             for(int i=0; i<26; i++)
//             {
//                 if(differ[i]!=0)
//                 {
//                     is_diff = true;
//                     break;
//                 }
//             }

//             if(!is_diff)
//             {
//                 ans.push_back(lp);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int slen=s.size(), plen=p.size();
        if(slen<plen)
        {
            return ans;
        }

        vector<int> cnt(26);
        for(int i=0; i<plen; i++)
        {
            cnt[s[i]-'a']++;
            cnt[p[i]-'a']--;
        }

        int differ=0;   // 其实用unsign更好理解，这是“不一致”的情况数量
        for(int i=0; i<26; i++)
        {
            if(cnt[i]!=0)
            {
                differ++;
            }
        }

        if(differ==0)
        {
            ans.push_back(0);
        }

        for(int lp=1; lp<slen-plen+1; lp++)
        {
            // 先处理左指针lp右移1格
            if(cnt[s[lp-1]-'a']==1)
            {
                // 本来的s[lp-1]使得s比p多了1个字母，移走了就少1个，正好就一样了，不一致减少1
                differ--;
            }
            else if(cnt[s[lp-1]-'a']==0)
            {
                // 本来是一致的，结果移走了，s少一个字母，新出现了一个不一致，differ就增加一个
                differ++;
            }
            cnt[s[lp-1]-'a']--;

            // 处理右指针lp+plen-1
            if(cnt[s[lp+plen-1]-'a']==-1)
            {
                // 本来少一个，右移正好加了一个，一致。不一致-1
                differ--;
            }
            else if(cnt[s[lp+plen-1]-'a']==0)
            {
                // 本来一致，多了一个，就不一致了
                differ++;
            }
            cnt[s[lp+plen-1]-'a']++;

            if(differ==0)
            {
                ans.push_back(lp);
            }
        }

        return ans;
    }
};

int main()
{
    string s = "cbaebabacd", p = "abc";
    Solution slt;
    vector<int> ans = slt.findAnagrams(s, p);
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}