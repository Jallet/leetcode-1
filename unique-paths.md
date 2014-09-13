[https://oj.leetcode.com/problems/unique-paths/](https://oj.leetcode.com/problems/unique-paths/)

```
class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<int> f(n, 0);
		f[0] = 1;
		for (size_t i = 0; i < m; i++){
			for (size_t j = 1; j < n; j++)
				f[j] = f[j] + f[j - 1];
		}
		return f[n - 1];
	}
};
```
