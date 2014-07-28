[https://oj.leetcode.com/problems/single-number/](https://oj.leetcode.com/problems/single-number/)

``` cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
		int re = A[0];
		for (size_t i = 1; i < n; i++){
			re ^= A[i];
		}
		return re;
	}
};
```
