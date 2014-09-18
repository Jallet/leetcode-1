``` cpp
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> r(num1.size() + num2.size() + 1, 0);
		
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (size_t i = 0; i < num1.size(); i++){
			int c = 0;
			for (size_t j = 0; j < num2.size(); j++){
				r[i + j] += (num1[i] - '0') * (num2[j] - '0') + c;
				c = r[i + j] / 10;
				r[i + j] %= 10;
			}
			r[i + num2.size()] += c;
		}
		reverse(r.begin(), r.end());
		string t;
		bool start = false;
		for (auto i : r){
			if (i != 0) start = true;
			if (start) t += (i + '0');
		}
		return t;
	}
};
```
