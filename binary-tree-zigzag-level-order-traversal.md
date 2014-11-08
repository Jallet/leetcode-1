``` cpp
class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > r;
		if (root == nullptr) return r;
		queue<pair<TreeNode*, int> > q;
		q.push(make_pair(root, 0));
		while (!q.empty()){
			int j = q.front().second;
			vector<int> t;
			while (!q.empty() && q.front().second == j){
				auto n = q.front().first;
				if (j % 2 == 1) t.insert(t.begin(), n->val);
				else t.push_back(n->val);
				if (n->left) q.push(make_pair(n->left, j + 1));
				if (n->right) q.push(make_pair(n->right, j + 1));
				q.pop();
			}
			r.push_back(t);
		}
		return r;
	}
};
```
