``` cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        if(n < 1) return NULL;
        return helper(num, 0, n - 1);
    }
    
    TreeNode* helper(vector<int> &num, int start, int end){
        if (start > end) return NULL;
        int mid = start + (end - start)/ 2;
        TreeNode * p = new TreeNode(num[mid]);
        p -> left = helper(num, start, mid - 1);
        p -> right = helper(num, mid + 1, end);
        return p;
    }
};
```
