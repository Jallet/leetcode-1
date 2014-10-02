``` cpp
class Solution {
public:
    void sortColors(int A[], int n) {
        int colorIndex[3] = {0};
        for(int i = 0; i < n; i++)
        {
            int color = A[i];
            for (int j = 2; j >= color; j--)
                A[colorIndex[j]++] = j;
        }
    }
};
```
