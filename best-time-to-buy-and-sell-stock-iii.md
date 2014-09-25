``` cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()<2) return 0;
        int len=prices.size(),result=0;
        int low=prices[0],high=prices[len-1];

        vector<int> profits_history(len,0);

        for (int i=0;i<len;i++){
            low=min(low,prices[i]);
            result=max(result,prices[i]-low);
            profits_history[i]=result; 
        }

        for (int i=len-1;i>=0;i--){
            high=max(high,prices[i]);
            result=max(result,high-prices[i]+profits_history[i]);
        }
        return result;
    }
};
```
