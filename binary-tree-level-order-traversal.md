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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> r;
        if(root == nullptr) return r;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            TreeNode* p = q.front().first;
            int i = q.front().second;
            if(r.size() < (i + 1)) r.resize(i + 1);
            r[i].push_back(p->val);
            if(p -> left) q.push(make_pair(p->left, i+1));
            if(p -> right) q.push(make_pair(p -> right, i+1));
            q.pop();
        }
        return r;
    }
};
```
