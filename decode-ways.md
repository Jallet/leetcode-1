``` cpp
class Solution {
public:
	int numDecodings(string s) {
		if (s == "") return 0;
		vector<int> f(s.size() + 1, 0);
		f[0] = 1;
		for (size_t i = 0; i < s.size(); i++){
			f[i + 1] = s[i] == '0' ? 0: f[i];
			if (i && (s[i - 1] != '0' && (s[i - 1] < '2' || s[i - 1] == '2' && s[i] <= '6')))
				f[i + 1] += f[i - 1];
		}
		return f.back();
	}
};
```
