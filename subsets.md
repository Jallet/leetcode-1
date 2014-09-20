bitmap
``` cpp
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int N = S.size();
    
        sort(S.begin(), S.end());
    
        vector<vector<int> > result;
        vector<int> tmp;
        bool exist;
    
        for(int i = 0; i < pow(2, N); i++){
            tmp.clear();
            for(int j = 0; j < N; j++){
                if((i >> j) & 1){
                    tmp.push_back(S[j]);
                }
            }
            result.push_back(tmp);
        }
    
        return result;
    }

};
```
