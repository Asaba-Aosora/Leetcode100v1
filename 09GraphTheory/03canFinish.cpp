// 其实就是判断有没有环

// 得到一种拓扑排序

// dfs: 逆向排序, 先入栈的是最后修的
class Solution {
    vector<vector<int>> edges;      // <先修, 后修>, 访问到先修课程时, 保证已访问所有其后修课程, 并已入栈. 这样栈顶到栈底即为一个拓扑排序
    vector<int> visited;            // 0: 未访问    1: 访问中   2: 已访问;      同时有栈的作用, 已访问即已入栈, 访问中即到它了但未入栈, 可能有环
    bool valid = true;                     // 有效性指标

    void dfs(int u)
    {
        // u 是第u门课程, 要搜索其所有后修课程都已访问
        // 先把u改为 "访问中"
        visited[u] = 1;
        for(int v: edges[u])
        {
            // visited[v]==2 可以直接跳过
            if(visited[v]==0)
            {
                dfs(v);
                if(!valid)
                {
                    return;
                }
            }
            else if(visited[v]==1)
            {
                valid = false;
                return;
            }

        }

        visited[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& v : prerequisites)
        {
            edges[v[1]].push_back(v[0]);
        }

        for(int i=0; i<numCourses && valid; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }

        return valid;
    }
};

// bfs: 正向, 先找没有入边的节点放在最前面
class Solution {
    vector<vector<int>> edges;
    vector<int> indeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);

        for(const auto& info: prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }

        queue<int> q;   // 当前入度为0的点
        for(int i=0; i<numCourses; i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }

        int visited = 0;    // 为什么现在才为0? 要 "已访问", 不要 "访问中"
        while(!q.empty())   // 终止条件: 没有入度为0的点. 两种情况: 全部访问完了 || 除了环都访问完了
        {
            visited++;
            int u = q.front();
            q.pop();

            for(int v: edges[u])
            {
                indeg[v]--;
                if(indeg[v]==0)
                {
                    q.push(v);
                }
            }
        }

        return visited==numCourses ? true : false;
    }
};