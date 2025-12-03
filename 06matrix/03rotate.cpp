// 把矩阵分成四块，对一块进行遍历，对每个点用一个tmp处理相应的四个点
// matrix[i][j] -> matrix[j][n-1-i] -> matrix[n-1-i][n-1-j] -> matrix[n-1-j][i] -> matrix[i][j]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();      // m==n 方阵

        for(int i=0; i<n/2; i++)
        {
            for(int j=0; j<(n+1)/2; j++)
            {
                // n为奇数时，按列多取一列、按行少取一行
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};