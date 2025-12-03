// 岛屿数量
// dfs/bfs/并查集

// 先做一个dfs吧
class Solution {
    vector<vector<bool>> visit;

    void dfs(const vector<vector<char>>& grid, int row, int col)
    {
        visit[row][col] = true;
        // 朝四个方向递归
        int m = grid.size();
        int n = grid[0].size();

        if(row+1<m && grid[row+1][col]=='1' && !visit[row+1][col])      dfs(grid, row+1, col);
        if(row>0 && grid[row-1][col]=='1' && !visit[row-1][col])        dfs(grid, row-1, col);
        if(col+1<n && grid[row][col+1]=='1' && !visit[row][col+1])      dfs(grid, row, col+1);
        if(col>0 && grid[row][col-1]=='1' && !visit[row][col-1])        dfs(grid, row, col-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        visit.resize(rows, vector<bool>(cols));

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j]=='1' && !visit[i][j])
                {
                    // 没到过这个有岛屿的地方，开始dfs，dfs会改访问
                    ans++;
                    dfs(grid, i, j);
                }

            }
        }

        return ans;
    }
};


// bfs
class Solution {
    vector<vector<bool>> visit;
    int m, n;

    void bfs(const vector<vector<char>>& grid, int r, int c)
    {
        visit[r][c] = true;

        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty())
        {
            // to do
            // 真的不想写了，好麻烦啊，设方向向量都很麻烦
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = gird[0].size();
        visit.resize(m, vector<bool>(n));
        int ans = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1' && !visit[i][j])
                {
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};


// 并查集
// 合并，查找，路径压缩

// 直接把并查集的类维护出来
class UnionFind
{
    vector<int> parent;     // 存根节点
    vector<int> rank;       // 秩
    int count;              // 岛屿数量

public:
    // 构造函数
    UnionFind(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 有岛屿才参加岛屿计数，水域直接设为非法
                if(grid[i][j]=='1')
                {
                    parent.push_back(n*i+j);    // 拉成一维
                    // 注意，这里要更新count！
                    count++;
                }
                else
                {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    // 查
    int find(int x)
    {
        // 根节点是自己等于自己，其他的要往上查找
        // 最好的实现是，树的深度最大两层，要么自己是根节点，要么自己直接连在根节点上
        if(x != parent[x])      // 不需要while，内部有递归，而且我不改x的
        {
            // x = parent[x];       // 不要这样写，这样还是回溯，没有能够压缩路径
            parent[x] = find(parent[x]);    // 递归，把每一个子节点都连到根节点上
        }
        return parent[x];
    }

    // 并
    void unite(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x!=root_y)
        {
            if(rank[root_x]<rank[root_y])
            {
                swap(root_x, root_y);
            }
            // 现在root_x的秩更大，把秩较小的root_y合并到秩更大的root_x下
            // 为了让find时的复杂度更低，要让小树连到大树上，改动更少
            parent[root_y] = root_x;
            if(rank[root_x]==rank[root_y])  rank[root_x]++;
            count--;        // 合并了之后，岛屿数量减少
        }
    }

    // 岛屿数量，比一般的并查集多一个“返回岛屿数”的函数
    int getCount()
    {
        return count;
    }

};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        UnionFind uf(grid);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    // 直接改成0，防止重复访问。
                    // eg: (1, 1) -> (1, 2)合并过了，那(1, 2)时就不用再合并了。
                    // 但(1, 2)要合并其他的，所以(1, 2)不能改，但是可以把(1, 1)标记为已访问
                    grid[i][j] = '0';
                    if(i+1<m && grid[i+1][j]=='1')  uf.unite(i*n+j, (i+1)*n+j);
                    if(i>0 && grid[i-1][j]=='1')    uf.unite(i*n+j, (i-1)*n+j);
                    if(j+1<n && grid[i][j+1]=='1')  uf.unite(i*n+j, i*n+j+1);
                    if(j>0 && grid[i][j-1]=='1')    uf.unite(i*n+j, i*n+j-1);
                }

            }
        }

        return uf.getCount();
    }
};