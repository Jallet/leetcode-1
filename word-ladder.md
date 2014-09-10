[https://oj.leetcode.com/problems/word-ladder/](https://oj.leetcode.com/problems/word-ladder/)

``` cpp
class Solution {
public:
	//leetcode word ladder
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		unordered_map<string, int> d;
		queue<string> q;
		q.push(start);
		d[start] = 0;
		dict.insert(end);
		while (!q.empty()){
			auto str = q.front();
			auto dd = d[str];
			q.pop();
			for (int j = 0; j < str.size(); j++){
				auto tmp = str[j];
				for (int i = 'a'; i < 'z' + 1; i++){
					str[j] = i;
					if (dict.count(str)){
						q.push(str);
						d[str] = (dd + 1);
						dict.erase(str);
						continue;
					}
				}
				str[j] = tmp;
			}
		}
		return d.count(end) ? d[end] + 1 : 0;
	}
};
```
