``` cpp
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (size_t i = 0; i < n;){
			if (A[i] < n && A[i] >= 0 && A[i] != i && A[A[i]] != A[i]){
				swap(A[i], A[A[i]]);
			}
			else i++;
		}
		for (int i = 1; i < n; i++){
			if (i != A[i]) return i;
		}
	}
};
```
