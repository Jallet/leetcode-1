``` cpp
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = strlen(s);
		if (len == 0) return 0;
		int count = 0, i = len - 1;
		for (i = len - 1; i >= 0; i--){
			if (!isspace(s[i])) break;
		}
		for (; i >= 0; i--){
			if (isspace(s[i])) break;
			count++;
		}
		return count;
	}
};
```
