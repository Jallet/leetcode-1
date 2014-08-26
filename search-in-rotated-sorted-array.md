[https://oj.leetcode.com/problems/search-in-rotated-sorted-array/](https://oj.leetcode.com/problems/search-in-rotated-sorted-array/)
``` cpp
class Solution {
public:
    //Search in Rotated Sorted Array
	int search(int A[], int n, int target) {
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (A[mid] == target)
				return mid;
			if (A[l] < A[mid]){
				if (target >= A[l] && target <= A[mid]) r = mid;
				else l = mid + 1 ;
			}
			else{
				if (target >= A[mid] && target <= A[r - 1]) l = mid + 1;
				else r = mid;
			}
		}
		return -1;
	}
};
```
