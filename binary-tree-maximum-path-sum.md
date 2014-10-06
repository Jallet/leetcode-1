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
    int maxPathSum(TreeNode *root) {
        int mx = INT_MIN, ans = INT_MIN;
        helper(root, mx, ans);
        return mx < 0? mx : ans;
    }
    
    int helper(TreeNode* p, int &mx, int &ans){
        if(! p) return 0;
        mx = max(mx, p -> val);
        int l = helper(p -> left, mx, ans),r = helper(p -> right, mx, ans);
        ans = max(ans, l+p->val+r);
        return max(max(l, r)+p->val, 0);
    }
};
```
