``` cpp
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> r;
		if (numRows == 0) return r;
		r = { { 1 } };
		for (size_t i = 1; i < numRows; i++){
			vector<int> t;
			for (size_t j = 0; j <= i; j++){
				if (j == i) t.push_back(r[i - 1][j - 1]);
				else if (j == 0) t.push_back(r[i - 1][0]);
				else t.push_back(r[i - 1][j - 1] + r[i - 1][j]);
			}
			r.push_back(t);
		}
		return r;
	}
};
```
