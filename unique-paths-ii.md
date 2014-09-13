[https://oj.leetcode.com/problems/unique-paths-ii/](https://oj.leetcode.com/problems/unique-paths-ii/)

``` cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
		vector<int> f(n, 0);
		f[0] = 1;
		for (size_t i = 0; i < m; i++){
			for (size_t j = 0; j < n; j++){
				 if (obstacleGrid[i][j] == 1) f[j] = 0;
                 else if (j) f[j] += f[j-1];
			}
		}
		return f[n - 1];
    }
};
```
