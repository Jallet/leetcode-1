[https://oj.leetcode.com/problems/word-break/](https://oj.leetcode.com/problems/word-break/)

DP

``` cpp
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> f(s.size() + 1, false);
		f[0] = true;
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size()];
	}
};
```

DFS，超时

``` cpp
class Solution {
public:
    	bool wordBreak(string s, unordered_set<string> &dict) {
		return dfs(s, dict, 0, 0);
	}
private:
	static bool dfs(const string &s, unordered_set<string> &dict,
		size_t start, size_t cur) {/*退栈调用*/
		if (cur == s.size()) {
			return dict.find(s.substr(start, cur - start + 1)) != dict.end();
		}
		if (dfs(s, dict, start, cur + 1)) return true;
		if (dict.find(s.substr(start, cur - start + 1)) != dict.end())
			if (dfs(s, dict, cur + 1, cur + 1)) return true;
		return false;
	}
};
```
