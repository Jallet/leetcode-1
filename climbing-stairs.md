[https://oj.leetcode.com/problems/climbing-stairs/](https://oj.leetcode.com/problems/climbing-stairs/)

``` cpp
class Solution {
public:
    // LeetCode, Climbing Stairs
	// 迭代，时间复杂度 O(n)，空间复杂度 O(1)
	// f(n) = f (n - 1) + f( n - 2 )
	int climbStairs(int n) {
		int sum = 1, prev = 0;
		int iter = 0;
		while (iter < n){
			iter++;
			auto tmp = sum;
			sum += prev;
			prev = tmp;
		}
		return sum;
	}
};
```
