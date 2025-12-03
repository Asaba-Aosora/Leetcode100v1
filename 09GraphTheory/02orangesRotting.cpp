// 多源最短路径
// 多个起点的bfs？

class Solution {
    // 方向变量
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        int cnt = 0;    // 剩下的新鲜橘子数量
        queue<pair<int, int>> q;    // 存坐标，腐烂橘子

        // 第一次遍历，初始化q和cnt
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)     // 不对，这是int，不是char！
                {
                    q.push({i, j});
                    // grid[i][j] = '0';   // 防止重复
                    // 只要后续只往新鲜橘子里搜索，就不用管腐烂橘子
                }
                else if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }

        // bfs
        while(cnt && !q.empty())
        {
            int sz = q.size();
            for(int k=0; k<sz && cnt; k++)
            {
                auto result = q.front();
                q.pop();
                int r = result.first;
                int c = result.second;
                for(int i=0; i<4; i++)
                {
                    int dr = dir[i][0];
                    int dc = dir[i][1];
                    if(r+dr>=0 && r+dr<m && c+dc>=0 && c+dc<n && grid[r+dr][c+dc]==1)
                    {
                        cnt--;
                        grid[r+dr][c+dc] = 2;
                        q.push({r+dr, c+dc});
                        if(cnt==0)  break;
                    }
                }
            }
            ret++;
        }

        return cnt ? -1 : ret;
    }
};