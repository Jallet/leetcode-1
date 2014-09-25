``` cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        int l = prices[0];
        int s = 0, sum = 0;
        for(size_t i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i - 1]) s = max( s, prices[i] - l);
            else l = prices[i], sum += s, s = 0;
        }
        return sum + s;
    }
};
```
