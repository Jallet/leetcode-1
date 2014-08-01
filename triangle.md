[https://oj.leetcode.com/problems/triangle/](https://oj.leetcode.com/problems/triangle/)

``` cpp
class Solution {
public:
    template<typename T>
	static inline T min(const T &a, const T &b){
		return a > b ? b : a;
	}
	/*
	template<typename T>
	static inline T max(const T &a, const T &b){
		return a > b ? a : b;
	}
	*/

	int minimumTotal(vector<vector<int> > &triangle) {
		for (int i = triangle.size() - 2; i >= 0; i--){
			for (size_t j = 0; j <= i; j++)
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
		return triangle[0][0];
	}
};
```
