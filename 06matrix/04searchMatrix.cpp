// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();  // num of rows
//         int n = matrix[0].size();   // num of cols
//         int j=0, i=0;       // 答案的横纵坐标

//         // 先遍历第0行，存在一起的，更快
//         while(j<n)
//         {
//             if(matrix[0][j]==target)
//             {
//                 return true;
//             }
//             if(matrix[0][j]>target)
//             {
//                 if(j==0)
//                 {
//                     return false;
//                 }
//                 break;      // 多加了一次
//             }
//             j++;    // j=n退出时，也是多加了一次
//         }
//         j--;    // 所以可以统一减回来


//         while(i<m)
//         {
//             if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//             // 这儿可以写++i，因为后面没有需要用到i的了，多加一次也无所谓
//             // 错！防止越界懂不懂
//             // 不对，matrix[i-1][j] 和 matrix[i][j-1] 的大小不能比较
//             if(matrix[i][j]>target)
//             {
//                 return false;
//             }
//             i++;
//         }
//         return false;
//     }
// };

// 其实大思路是对的，不过没有考虑到 matrix[i-1][j] 和 matrix[i][j-1] 不能比较
// 从右上角开始遍历，这个点是横行里最大、纵列里最小
// 所以可以根据     target>m[i][j] -> 排除i横行
//                 target<m[i][j] -> 排除j纵列
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0, j=n-1;
        
        while(i<m && j>=0)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return false;
    }
};