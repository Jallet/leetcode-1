[https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/](https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/)
``` cpp  
  class Solution {
  public:
      int removeDuplicates(int A[], int n) {
          return distance(A, unique(A, A + n));
      }
  };
```
