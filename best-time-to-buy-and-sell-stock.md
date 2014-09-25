``` cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        int l = prices[0];
        int s = 0;
        for(size_t i = 1; i < prices.size(); i++){
            if (prices[i] > l) s = max( s, prices[i] - l);
            else l = prices[i];
        }
        return s;
    }
};
```
