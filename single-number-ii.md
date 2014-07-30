[https://oj.leetcode.com/problems/single-number-ii/](https://oj.leetcode.com/problems/single-number-ii/)

``` cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
		vector<int> v(32,0);
		for (size_t i = 0; i != n; i++){
			for (size_t j = 0; j != 32; j++)
				v[j] += 1 & (A[i] >> j);
		}
		int re = 0;
		for (size_t i = 0; i < 32; i++)
			re += (v[i]%3) << i;
		return re;
	}
};
```
