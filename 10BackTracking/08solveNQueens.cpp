// n皇后问题
// 横行, 纵列, 两条斜线 都不能重复
// 遍历需要 O(N!), 而最好能让查找是 O(1)

// 1. 利用哈希集合
// 2. 位图
class Solution {
    unordered_set<int> cols;    // 已有的列
    unordered_set<int> diag1;   // c == r + i
    unordered_set<int> diag2;   // r + c == i
    vector<vector<string>> ans;
    vector<int> pos;            // pos[i]=j 就是在 (i,j) 放置了皇后

    void backtrack(int n, int r)
    {
        // r: 待处理的行
        if(r==n)
        {
            // 要把 pos 转化为输出的形式, 单独调用一个函数
            genBoard(n);
            return;
        }

        // 直接遍历列数
        for(int c=0; c<n; c++)
        {
            if(cols.count(c))
            {
                continue;
            }
            if(diag1.count(c-r))
            {
                continue;
            }
            if(diag2.count(c+r))
            {
                continue;
            }
            // 走到这里就是合法的位置
            cols.insert(c);
            diag1.insert(c-r);
            diag2.insert(c+r);
            pos[r] = c;
            backtrack(n, r+1);
            cols.erase(c);
            diag1.erase(c-r);
            diag2.erase(c+r);
            pos[r] = -1;
        }

    }

    void genBoard(int n)
    {
        vector<string> t(n, string(n, '.'));
        for(int i=0; i<n && pos[i]!=-1; i++)
        {
            t[i][pos[i]] = 'Q';
        }
        ans.emplace_back(t);
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        pos.resize(n, -1);  // 若置0, 区分不了是否非法
        backtrack(n, 0);
        
        return ans;
    }
};