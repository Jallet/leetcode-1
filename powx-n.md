[https://oj.leetcode.com/problems/powx-n/](https://oj.leetcode.com/problems/powx-n/)

``` cpp
class Solution {
public:
	double pow(double x, int n){
		if (n < 0) return 1.0 / _pow(x, -n);
		return _pow(x, n);
	}

	double _pow(double x, int n){
		if (n == 0) return 1;
		double v = _pow(x, n / 2);
		if (n % 2 == 1) return v *v *x;
		return v *v;
	}
};
```
