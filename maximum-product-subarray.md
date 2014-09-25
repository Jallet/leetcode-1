``` cpp
class Solution {
public:
    int maxProduct(int a[], int n) {
        vector<int> f(n, INT_MIN);
        vector<int> g(n, INT_MAX);
        int l = f[0] = g[0] = a[0];
        for(size_t i = 1; i < n; i++){
            f[i] = max(max(f[i - 1] * a[i], g[i - 1] * a[i] ), a[i]);
            g[i] = min(min(g[i - 1] * a[i], f[i - 1] * a[i] ), a[i]);
            l = max(l, f[i]);
        }
        return l;
    }
};
```
