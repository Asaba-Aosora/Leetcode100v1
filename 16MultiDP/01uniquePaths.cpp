// 这不是数学题吗
// 不会是组合数很难求吧
// 的确。。。爆掉了
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n) swap(m,n);
        // 保证m比n小
        // 求 C(m-1, m+n-2)
        int up=1, down=1;
        for(int i=0; i<m-1; i++)
        {
            up *= (m+n-2-i);
            down *= (m-1-i);
        }
        return up/down;
    }
};

// 可以优化！
// 算 C^1_n，然后C^2_n这样递推，每次因为组合数结果必为整数，所以可以边乘边除
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 算 C^{m-1}_{m+n-2}
        if(m>n) swap(m,n);
        long long ans = 1;
        for(int x=1,y=m+n-2; x<m; x++,y--)
        {
            ans = (ans * y / x);
        }

        return ans;
    }
};

// dp懒得做了，大概意思就是第一列和第一行都是1
// 其他 dp[i][j] = dp[i-1][j] + dp[i][j-1]
// 可以发现，只需要i-1行的数据，所以可以滚动数组优化空间