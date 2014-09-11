[https://oj.leetcode.com/problems/candy/](https://oj.leetcode.com/problems/candy/)

``` cpp
class Solution {
public:
	int candy(vector<int> &ratings) {
		if (ratings.size() < 2) return 1;
		vector<int> candys(ratings.size(), 1);
		for (size_t i = 1; i < ratings.size(); i++){
			if (ratings[i] > ratings[i - 1]) candys[i] = max(candys[i], candys[i - 1] + 1);
		}

		for (int i = ratings.size() - 2; i >= 0; i--){
			if (ratings[i] > ratings[i + 1]) candys[i] = max(candys[i],(candys[i + 1] + 1));
		}
		return accumulate(candys.begin(), candys.end(), 0);
	}
};
```
