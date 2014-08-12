[https://oj.leetcode.com/problems/jump-game/](https://oj.leetcode.com/problems/jump-game/)
``` cpp
class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> f(n, 0);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1], A[i - 1]) - 1;
            if (f[i] < 0) return false;;
        }
        return f[n - 1] >= 0;
    }
};
```
