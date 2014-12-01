``` java
public class Solution {
    public String minWindow(String S, String T) {
		int[] srcHash = new int[1000];
		for(int i = 0; i < T.length(); i++){
			srcHash[T.charAt(i)]++;
		}
		int start = 0,i= 0;
		int[] destHash = new int[1000];
		int found = 0;
		int begin = -1, end = S.length(), minLength = 1 + S.length();
		for(start = i = 0; i < S.length(); i++){
			if(srcHash[S.charAt(i)]!=0){
				destHash[S.charAt(i)]++;
				if(destHash[S.charAt(i)] <= srcHash[S.charAt(i)]) found++;
				if(found == T.length()){
					//find the first window that satisfied this condition					
					//next step : shrink the window size
//					System.out.println(S.substring(start, i + 1));
					while(start < i){
						if(srcHash[S.charAt(start)] == 0 || (srcHash[S.charAt(start)] != 0 && (--destHash[S.charAt(start)]) >= srcHash[S.charAt(start)])) {
							start++;
						}else {
							break;
						}
					}
					if(i - start + 1< minLength){
						minLength = i - start + 1;
						begin = start;
						end = i;
					}
					found--;
					start++;
				}
			}
		}
		return begin == -1 ? "" : S.substring(begin,end + 1);
	}
}
```
