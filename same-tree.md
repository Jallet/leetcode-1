[https://oj.leetcode.com/problems/same-tree/](https://oj.leetcode.com/problems/same-tree/)

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
		if (!p && !q) return true; // 终止条件
		if (!p || !q) return false; // 剪枝
		return p->val == q->val // 三方合并
			&& isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}
};
```
