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
     int minDepth(TreeNode *root) {
        if (NULL == root) return 0;
        if (NULL == root->left && NULL == root->right) {
            return 1;
        }
    
        int minDepthTree = INT_MAX;
        if (NULL != root->left) {
            minDepthTree = min(minDepthTree, minDepth(root->left) + 1);
        }
        if (NULL != root->right) {
            minDepthTree = min(minDepthTree, minDepth(root->right) + 1);
        }
    
        return minDepthTree;
    }
};
```
