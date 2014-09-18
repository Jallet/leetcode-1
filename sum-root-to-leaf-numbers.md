``` cpp
class Solution {
public:
	vector<int> r;

	int sumNumbers(TreeNode *root) {
		if (root == nullptr) return 0;
		r.clear();
		helper(root, 0);
		return accumulate(r.begin(),r.end(), 0);
	}

	void helper(TreeNode* root, int sum){
		if ((root->right || root->left) == NULL){
			r.push_back(sum + root->val);
			return;
		}
		
		if (root->left != nullptr){
			helper(root->left, (sum + root->val) * 10);
		}

		if (root->right != nullptr){
			helper(root->right, (sum + root->val) *10);
		}
	}
};

```
