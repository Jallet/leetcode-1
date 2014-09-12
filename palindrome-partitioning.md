[]()

``` cpp
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<string> v; 
		if (s.size() == 0) return result;
		
		dfs(s, v);
		return result;
	}
private:
	bool is_Palindrome(string str){
		int a = 0, b = str.size() - 1;
		while (a < b)
			if (str[a++] != str[b--]) return false;
		return true;
	}

	void dfs(string str, vector<string> v){
		if (str.size() == 0){
			result.push_back(v);
			return;
		}
		for (size_t i = 1; i <= str.size(); i++){
			auto sub = str.substr(0, i);
			if (is_Palindrome(sub)){
				v.push_back(sub);
				dfs(str.substr(i, str.size() - i), v);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> result;
};
```
