N方的解法会超时

``` cpp
class Solution {
public:
    int maxArea(vector<int> &height) {
        int m = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i + 1; j < height.size(); j++){
                m = max(m, (j - i) * min(height[i], height[j]));
            }
        }
        return m;
    }
};
```
夹逼

``` cpp
class Solution {
public:
    int maxArea(vector<int> &height) {
        int m = 0; 
        for(int i = 0, j = height.size() - 1; i < j;){
            m = max(m, min(height[i], height[j])*(j - i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return m;
    }
};
```
