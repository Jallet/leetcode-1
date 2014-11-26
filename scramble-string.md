``` java
public class Solution {
    public boolean isScramble(String s1, String s2) {
        int len = s1.length();
        if(len!=s2.length()){
            return false;
        }
        if(len==0){
            return true;
        }
        
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        
        boolean[][][] result = new boolean[len][len][len];
        for(int i=0;i<len;++i){
            for(int j=0;j<len;++j){
                result[0][i][j] = (c1[i]==c2[j]);
            }
        }
        
        for(int k=2;k<=len;++k){
            for(int i=len-k;i>=0;--i){
              for(int j=len-k;j>=0;--j){
                  boolean r = false;
                  for(int m=1;m<k && !r;++m){
                      r = (result[m-1][i][j] && result[k-m-1][i+m][j+m]) || (result[m-1][i][j+k-m] && result[k-m-1][i+m][j]);
                  }
                  result[k-1][i][j] = r;
              }
            }
        }
        
        return result[len-1][0][0];
    }
}
```
