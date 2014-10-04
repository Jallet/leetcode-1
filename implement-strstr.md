``` cpp
class Solution {
public:
    char *strStr(char *s, char *t) {
        if(s == nullptr || t == nullptr || strlen(t) == 0) return s;
        if(strlen(s) < strlen(t)) return NULL;
        for(size_t i = 0; i < strlen(s) - strlen(t) + 1; i++){
            bool b = true;
            if(s[i] == *t){
                for(size_t j = 1; j < strlen(t); j++){
                    if(s[i + j] != t[j]){
                        b = false;
                        break;
                    }
                }
                if(b) return s + i;
            }
        }
        return NULL;
    }
};
```
