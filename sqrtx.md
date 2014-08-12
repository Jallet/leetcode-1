[https://oj.leetcode.com/problems/sqrtx/](https://oj.leetcode.com/problems/sqrtx/)
``` cpp
class Solution {
public:
    int sqrt(int x){
		int start = 1, end = x;
		int last_mid;
		if (x < 2) return x;
		while (start <= end){
			int mid = (start + end) / 2;
			//printf("%d\n", mid);
			if (x / mid > mid){
				start = mid + 1;
				last_mid = mid;
			}
			else if(x / mid < mid)
				end = mid - 1 ;
			else
				return mid;
		}
		return last_mid;
	}
};
```
