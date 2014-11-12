``` cpp
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while(r > (l + 1)){
            int m = l + (r - l) / 2;
            if(num[l] == num[r] || num[l] == num[m]){ l++; continue;}
            if(num[l] < num[m] && num[r] < num[m]){
                l = m;
            }
            else{
                r = m;
            }
        }
        if(r == (l + 1)) return min(num[l], num[r]);
        else return num[l];
    }
};
```
