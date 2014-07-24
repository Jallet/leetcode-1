[https://oj.leetcode.com/problems/string-to-integer-atoi/](https://oj.leetcode.com/problems/string-to-integer-atoi/)
这题有些疑问。。比如，可以AC的答案， 对于输入"++2"会返回0.

放一个我写的答案，不能AC

``` cpp
class Solution {
public:
    int atoi(const char *str) {
        int re = 0, base = 1;
		const char*  sp = str, *ep = str + strlen(str) - 1;

		while (*sp < '0' || *sp > '9') sp++;
		while (*ep < '0' || *ep > '9') ep--;

		while (sp <= ep--){
			re += base * (*ep - '0');
			if (re < 0 && sp > str && *(sp - 1) == '-') return INT_MIN; //溢出，符号反转
			if (re < 0) return INT_MAX;
			base *= 10;
		}

		if (sp > str && *(sp - 1) == '-') return 0 - re;
		return re;
    }
};
```
