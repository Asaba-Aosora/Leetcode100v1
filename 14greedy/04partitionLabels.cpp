/*
    先进行一个预处理, 把每个字母最后出现的位置记录下来
    然后就可以像前面几道jump一样做了
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26);
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            lastPos[s[i]-'a'] = i;
        }
        vector<int> ans;
        int end=0;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            cnt++;
            end = max(end, lastPos[s[i]-'a']);
            if(i==end)
            {
                ans.push_back(cnt);
                cnt=0;
            }
        }
        return ans;
    }
};