
[https://oj.leetcode.com/problems/palindrome-partitioning-ii/](https://oj.leetcode.com/problems/palindrome-partitioning-ii/)

DP

``` cpp
class Solution {
public:
    int _minCut(string s, const int n){
		int f[n + 1];
		bool p[n][n];
		fill_n(&p[0][0], n * n, false);
		//the worst case is cutting by each char
		for (int i = 0; i <= n; i++)
			f[i] = n - 1 - i; // 最后一个 f[n]=-1 :9 8 7 6 5 4 3 2 1 0 -1
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];
	}

	int minCut(string s) {
		return _minCut(s, s.size());
	}
};
```
