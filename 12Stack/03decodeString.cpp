#include <iostream>
#include <string>
using namespace std;

class Solution {
    string ans;
    int n;
    int process(const string& s, int pos)
    {
        if(pos==n)  return 0;
        int len = 0;    // 代表已经处理的这一段s的长度，为递归能正确跳转做保障
        while(pos<n && s[pos]>='a'&&s[pos]<='z')
        {
            // 字母：直接加进ans
            ans += s[pos];
            pos++;
            len++;
        }
        // 退出的情况：1. 到 s.end() 了 2. 到 ']' 了 3. 到数字了
        if(pos==n || s[pos]==']')
        {
            return len;     // 此处的len就是已处理的子串长度, 没包含']'
        }

        int val = 0;
        while(pos<n && s[pos]>='0' && s[pos]<='9')
        {
            // 处理数字
            val *= 10;
            val += s[pos]-'0';
            pos++;
            len++;
        }

        // 倍数得到了，开始处理重复的部分
        // 现在的pos是'[', len 没包含 '['
        if(s[pos]=='[')
        {
            len++;
            pos++;
            int sublen=0;
            for(int i=0; i<val; i++)
            {
                sublen = process(s, pos);
            }
            len += sublen;
            pos += sublen;
            len++;
        }
        len += process(s, ++pos);
        return len;
    }
public:
    string decodeString(const string s) {
        n = s.size();
        process(s, 0);
        return ans;
    }
};

int main()
{
    string str = "3[a]2[bc]";
    Solution slt;
    cout << slt.decodeString(str);

    return 0;
}
