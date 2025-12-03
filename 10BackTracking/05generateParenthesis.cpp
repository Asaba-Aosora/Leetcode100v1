#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// 括号生成。两种模式：内部 / 右边
// 所以：递归生成 left, right, 返回 '(' + left + ')' + right
// class Solution {
//     shared_ptr<vector<string>> cache[10] = {nullptr};   // cache是一个指针数组，有10格，每一格是一个指针，这个指针是vector<string>

//     shared_ptr<vector<string>> generate(int n)
//     {
//         if(cache[n]!=nullptr)   return cache[n];
//         if(n==0)
//         {
//             cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
//             return cache[n];
//         }
//         shared_ptr<vector<string>> result = shared_ptr<vector<string>>(new vector<string>);
//         for(int i=0; i<n; i++)
//         {
//             auto lefts = generate(i);
//             auto rights = generate(n-i-1);
//             for(auto left: *lefts)      // 记得解引用
//             {
//                 for(auto right: *rights)
//                 {
//                     result->push_back('('+left+')'+right);
//                 }
//             }
//         }
//         cache[n] = result;
//         return cache[n];
//     }
// public:
//     vector<string> generateParenthesis(int n) {
//         return *generate(n);
//     }
// };

// 另一种思路难一点，但实现更简单的做法
// 保证前序合法的情况下，继续生成合法的括号对
// 要求：过程中左括号数>=右括号数, 结束时相等
class Solution {
    vector<string> ans;
    string t;

    void backtrack(int n, int l, int r)
    {
        if(l<r)     return;
        int sz = t.size();
        if(sz==2*n)
        {
            if(l==r)
            {
                ans.push_back(t);
            }
            return;
        }

        t.push_back('(');
        backtrack(n, l+1, r);
        t.pop_back();

        t.push_back(')');
        backtrack(n, l, r+1);
        t.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0);
        return ans;
    }
};

int main()
{
    Solution slt;
    int n=2;
    for(string str: slt.generateParenthesis(n))
    {
        cout << str << endl;
    }

    return 0;
}