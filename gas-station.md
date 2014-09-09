[https://oj.leetcode.com/problems/gas-station/](https://oj.leetcode.com/problems/gas-station/)

``` cpp
class Solution {
public:
	// LeetCode, Gas Station
	// 时间复杂度 O(n)，空间复杂度 O(1)
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
		auto sum = accumulate(gas.begin(), gas.end(), 0);
		auto cost_sum = accumulate(cost.begin(), cost.end(), 0);
		if (sum < cost_sum) return -1;

		auto r = 0, accu = 0;
		for (size_t i = 0; i < gas.size(); i++){
			if (gas[i] + accu < cost[i]) {
				r = i + 1;
				accu = 0;
			}
			else accu += gas[i] - cost[i];
		}
		return r;
	}
};

```
