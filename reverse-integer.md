[https://oj.leetcode.com/problems/reverse-integer/](https://oj.leetcode.com/problems/reverse-integer/)

``` cpp
class Solution {
public:
    int reverse(int x) {
        int re = 0;
		for (; x; x /= 10){
			re = re * 10 + x % 10;
		}
		return re;
    }
};
```
