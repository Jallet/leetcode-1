[https://oj.leetcode.com/problems/palindrome-number/](https://oj.leetcode.com/problems/palindrome-number/)

``` cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
		size_t len = 0;
		for (int y = x; y; y /= 10, len++);
		int s = 1;
		while (s < len){
			int low = (x % (int)(pow(10, s))) / (pow(10, s - 1));
			int high = (int)(x / (pow(10, (len)-1))) %10;
			--len,++s;
			if (low != high) return false;
		}
		return true;
    }
};
```
