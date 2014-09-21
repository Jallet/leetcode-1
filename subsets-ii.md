```
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		int N = S.size();
		sort(S.begin(), S.end());
		vector<vector<int>> r;
		vector<int> t;

		for (size_t i = 0; i < (1 << N); i++){
			t.clear();
			for (size_t j = 0; j < N; j++){
				if (i & 1<<j){ 
				    if(j && S[j] == S[j - 1] && !(i & 1<<j-1))
				        goto PAPA; 
				    else t.push_back(S[j]);
				}
			}
			r.push_back(t);
        PAPA:;
		}
		return r;
	}
};
```
