// 还是很简单的，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
// 然后可以优化掉空间
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // 行数，i的范围
        int n = grid[0].size();    // 列数，j的范围
        vector<int> dp(n);
        dp[0] = grid[0][0];

        // 初始化 i=0
        for(int j=1; j<n; j++)
        {
            dp[j] = dp[j-1] + grid[0][j];
        }
        
        // 开始逐行计算
        for(int i=1; i<m; i++)
        {
            dp[0] += grid[i][0];
            for(int j=1; j<n; j++)
            {
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6}
    };

    Solution slt;

    cout << slt.minPathSum(grid);

    return 0;
}