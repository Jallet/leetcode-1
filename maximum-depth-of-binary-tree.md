[https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/](https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/)

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
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root ->right));
    }
};

```
