// 先二分确定行，再二分确定列

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows;
        while(top<bottom)
        {
            int midr = (top + bottom) / 2;
            if(matrix[midr][0]==target)
            {
                return true;
            }
            else if(matrix[midr][0]<target)
            {
                top = midr+1;
            }
            else
            {
                bottom = midr;
            }
        }
        // 该插入的位置, 即 "下一行"
        int r = top-1;  // 减回来, 搜索这一行
        int left=0, right=cols;
        while(r>=0 && left<right)
        {
            int midc = (left+right)/2;
            if(matrix[r][midc]==target)
            {
                return true;
            }
            else if(matrix[r][midc]<target)
            {
                left = midc+1;
            }
            else
            {
                right = midc;
            }
        }
        return false;
    }
};