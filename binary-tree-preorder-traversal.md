[https://oj.leetcode.com/problems/binary-tree-preorder-traversal/](https://oj.leetcode.com/problems/binary-tree-preorder-traversal/)

``` cpp
class Solution{
public:
	vector<int> preorderTraversal(TreeNode *p)
	{
		vector<int> res;
		stack<TreeNode* > s;
		for (;;){
			while (p){
				res.push_back(p->val);
				if (p->right)
					s.push(p->right);
				p = p->left;
			}
			if (s.empty()) break;
			p = s.top();
			s.pop();
		}
		return res;
	}
};

```
