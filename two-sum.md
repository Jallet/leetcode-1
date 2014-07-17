(https://oj.leetcode.com/problems/two-sum/)[https://oj.leetcode.com/problems/two-sum/]

这题出的不是特别好，算法挺简单的，但是多余的处理又烦又多。。。。



``` cpp
class Solution {
public:
    size_t getIndex(vector<int> v, int value)
	{
		for (size_t i = 0; i < v.size(); i++){
			if (v[i] == value)
				return i + 1;
		}
	}

	size_t rgetIndex(vector<int> v, int value)
	{
		for (size_t i = v.size() - 1; i >= 0; i--){
			if (v[i] == value)
				return i + 1;
		}
	}
	
    vector<int> twoSum(vector<int> &number, int target) {
        vector<int> v(number);
		sort(v.begin(), v.end());
		vector<int> result;
		//vector<int>::iterator i = v.begin();
		//vector<int>::reverse_iterator j = v.rbegin();
		size_t i = 0;
		size_t j = v.size() - 1;
		while (i != j)
		{
			if (v[i] + v[j] == target)
			{
				result.push_back(getIndex(number, v[i]));
				result.push_back(rgetIndex(number, v[j]));
				sort(result.begin(), result.end());
				return result;
			}
			else if (v[i] + v[j] > target)
				j--;
			else
				i++;
		}
		return result;
    }
};
```
