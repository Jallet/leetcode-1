[https://oj.leetcode.com/problems/symmetric-tree/](https://oj.leetcode.com/problems/symmetric-tree/)
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
    bool isSymmetric(TreeNode *root) {
		return root ? isSymmetric(root->left, root->right) : true;
	}
	bool isSymmetric(TreeNode *left, TreeNode *right) {
		if (!left && !right) return true; // 终止条件
		if (!left || !right) return false; // 终止条件
		return left->val == right->val // 三方合并
			&& isSymmetric(left->left, right->right)
			&& isSymmetric(left->right, right->left);
	}
};
```
