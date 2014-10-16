``` cpp
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 1) return strs[0];
        string prefix;
        if(strs.size() == 0) return prefix;
        prefix = strs[0];
        int k = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] != prefix[j]){
                  k = min(j , k);
                  break;  
                } 
            }
            k = min(k, (int)strs[i].size());
        }
        return prefix.substr(0, k);
    }
};
```
