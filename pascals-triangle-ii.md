``` cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p, c;
        p.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            for(int j = 0; j <= i; j++){
                if(!j) c.push_back(p[j]);
                else if(j == i) c.push_back(p[j - 1]);
                else c.push_back(p[j - 1] + p[j]);
            }
            p = c;
            c.clear();
        }
        return p;
    }
};
```
