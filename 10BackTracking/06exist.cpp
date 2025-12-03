// 单词搜索
// 呃呃深搜?
// 啊啊啊超限了(爆哭)
// class Solution {
//     vector<vector<bool>> visited;
//     bool valid = false;
//     const vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//     void search(vector<vector<char>>& board, string word, char cur, queue<pair<int, int>>& q, int row, int col)
//     {
//         // cur 表示现在要找的字符, 是word的下标
//         // row 和 col 是上一个字符的位置
//         int sz = word.size();
//         if(cur==sz)
//         {
//             valid = true;
//             return;
//         }
//         int m = board.size();
//         int n = board[0].size();
//         if(cur==0)
//         {
//             for(int i=0; i<m; i++)
//             {
//                 for(int j=0; j<n; j++)
//                 {
//                     if(board[i][j]==word[0])
//                     {
//                         q.push({i, j});
//                     }
//                 }
//             }
//         }
//         else
//         {
//             for(int i=0; i<4; i++)
//             {
//                 int nr = row + dir[i][0];
//                 int nc = col + dir[i][1];
//                 if(nr>=0 && nr<m && nc>=0 && nc<n)
//                 {
//                     if(board[nr][nc]==word[cur] && !visited[nr][nc])    // 排除走过来的点
//                     {
//                         q.push({nr, nc});
//                     }
//                 }
//             }
//         }
//     }

//     void dfs(vector<vector<char>>& board, string word, char cur, int row=0, int col=0)
//     {
//         queue<pair<int, int>> q;    // <row, col>
//         search(board, word, cur, q, row, col);
//         while(!q.empty() && !valid)
//         {
//             auto tmp = q.front();
//             q.pop();
//             int nr = tmp.first;
//             int nc = tmp.second;
//             if(visited[nr][nc]==true)   continue;
//             visited[nr][nc] = true;
//             dfs(board, word, cur+1, nr, nc);
//             visited[nr][nc] = false;
//         }
//     }

// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size();
//         int n = board[0].size();
//         visited.resize(m, vector<bool>(n));
//         dfs(board, word, 0);
//         return valid;
//     }
// };


// dfs思路没问题, 但是要剪枝才不会超限
// 根本不需要把下一步路径存起来！可以直接在循环里面递归，回溯到这一步马上就能遍历到下一个值

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> visited;
    const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool check(int row, int col, int cur, vector<vector<char>>& board, string word)
    {
        // 终止条件
        if(cur==word.size())
        {
            return true;
        }
        // 确认从 (row, col) 位置开始，能够查找到 word[cur] 开始的子串
        if(row<0 || row==m || col<0 || col==n || board[row][col]!=word[cur] || visited[row][col])     return false;
        visited[row][col] = true;

        bool flag = false;
        for(auto dir: dirs)
        {
            int newrow = row + dir.first;
            int newcol = col + dir.second;
            // 如果这么写，如果正好最后一个是在边界上，那就不行了
            // if(newrow>=0 && newrow<m && newcol>=0 && newcol<n)
            // {
            //     flag = check(newrow, newcol, cur+1, board, word);
            //     if(flag)    break;
            // }
            flag = check(newrow, newcol, cur+1, board, word);
            if(flag)    break;
        }
        visited[row][col] = false;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<int>(n));

        bool flag = false;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                flag = check(i, j, 0, board, word);
                if(flag)    return flag;    // 这儿是两层循环，如果写break，就要写两个，不然flag会被覆盖
            }
        }
        return flag;
    }
};

int main()
{
    Solution slt;
    vector<vector<char>> board = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    cout<<slt.exist(board, word);

    return 0;
}