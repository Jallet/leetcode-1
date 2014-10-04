``` cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        string ss;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(auto i: s){
            if(isalnum(i)) ss.push_back(i);
        }
        for(int i = 0, j = ss.size() - 1; i <= j; i++, j--){
            if(ss[i] != ss[j]) return false;
        }
        return true;
    }
};
```
