// 螺旋矩阵，那就是不断缩小上下左右边界。起始L=0, R=n-1, U=1, D=m-1
// 每次抵达一个边界后，该边界值往内收1
// 根据边界来更新i, j
// 定义方向变量？这个操作：int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// ! 直接一圈一圈地来，就不需要管方向了。
// 每一圈都是   (top, left)          -> (top, right) 
//          -> (top+1, right)       -> (bottom, right) 
//          -> (bottom, right-1)    -> (bottom, left) 
//          -> (bottom+1, left)     -> (top-1, left)

// 然后各往内收就ok了

// 奇数层、最后一圈只有一半？没关系，大条件可以取等，小条件严格小于就ok

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m-1;
        int left =0;
        int right = n-1;
        vector<int> ans;

        while(top<=bottom && left<=right)
        {
            // (top, left) -> (top, right)
            // 按while的条件，至少有一个元素，可以往里放
            for(int i=left; i<=right; i++)
            {
                ans.push_back(matrix[top][i]);
            }

            if(top==bottom)
            {
                break;
            }

            // 以下必须有严格的 top<bottom, 如果最后top==bottom时，直接跳过循环了
            // (top+1, right) -> (bottom, right) 
            for(int i=top+1; i<=bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }

            // 提前保证left<right
            if(left==right)
            {
                break;
            }

            // 有严格的 left<right 以及 **先决条件** top<bottom
            // 然而此处for没有top<bottom的判断，所以提前判断
            // (bottom, right-1) -> (bottom, left)
            for(int i=right-1; i>=left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            // (bottom-1, left) -> (top+1, left)
            // 这里没有判left<right, 所以要提前退出
            for(int i=bottom-1; i>top; i--)
            {
                ans.push_back(matrix[i][left]);
            }

            left++;
            top++;
            right--;
            bottom--;
        }
        return ans;
    }
};