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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
	    
	    queue<pair<TreeNode*, int> > q;
		vector<vector<int> > r;
		if(root == nullptr) return r;
		vector<int> d;
		r.push_back(d);
		q.push(make_pair(root, 0));
		while (!q.empty()){
			auto tt = q.front();
			r.back().push_back(tt.first->val);
			if (tt.first->left) q.push(make_pair(tt.first->left, tt.second + 1));
			if (tt.first->right) q.push(make_pair(tt.first->right, tt.second + 1));
			q.pop();
			if (!q.empty()){
				if (q.front().second == (tt.second + 1)){
					vector<int> d;
					r.push_back(d);
				}
			}
		}
		reverse(r.begin(), r.end());
		return r;
	}
};
```
