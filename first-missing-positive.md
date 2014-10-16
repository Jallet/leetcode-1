``` cpp
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i)
        {
            int digit = A[i];
            while (digit <= n && digit > 0 && A[digit - 1] != digit)
            {
                swap(A[digit - 1], A[i]);
                digit = A[i];
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```
