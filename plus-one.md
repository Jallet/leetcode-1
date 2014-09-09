[https://oj.leetcode.com/problems/plus-one/](https://oj.leetcode.com/problems/plus-one/)

``` cpp

class Solution {
public:
    // LeetCode, Plus One
	// 时间复杂度 O(n)，空间复杂度 O(1)
	vector<int> plusOne(vector<int> &digits){
		return add(digits, 1);
	}

    template<typename T>
	vector<T> add(vector<T> &digits, T a){
		auto carry = a;
		for (auto i = digits.rbegin(); i != digits.rend(); i++){
			auto sum = carry + *i;
			*i= sum % 10;
			carry = sum / 10;
		}
		if (carry > 0) digits.insert(digits.begin(), 1);
		return digits;
	}
};
```
