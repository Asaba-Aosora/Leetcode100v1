#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false, row0 = false;
        int m = matrix.size();      // 行数
        int n = matrix[0].size();   // 列数

        // col0, row0 要作为标记，所以要提前记录其是否含0
        for(int i=0; i<m; i++)
        {
            if(matrix[i][0] ==0 )
            {
                col0 = true;
                break;
            }
        }

        for(int j=0; j<n; j++)
        {
            if(matrix[0][j] == 0)
            {
                row0 = true;
                break;
            }
        }

        // 注意不是从0开始遍历。以及，这个做法不会影响col0, row0的信息，只是把其中部分提前置0
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // 检查标记并置0。注意，从1开始遍历，因为matrix[0][0]其实不是标记位，如果它本来为0，就会抹去很多信息了
        for(int i=1; i<m; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j=0; j<n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1; j<n; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i=0; i<m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(col0 == true)
        {
            for(int i=0; i<m; i++)
            {
                matrix[i][0]=0;
            }
        }

        if(row0 == true)
        {
            for(int j=0; j<n; j++)
            {
                matrix[0][j]=0;
            }
        }

    }
};

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution slt;
    slt.setZeroes(matrix);

    return 0;
}