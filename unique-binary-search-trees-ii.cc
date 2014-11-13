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
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode *> helper(int l, int r){
        vector<TreeNode *> v;
        if(l > r) {
            v.push_back(NULL);
            return v;
        }
        for(int i = l; i <= r; i++){
            auto lv = helper(l, i- 1);
            auto rv = helper(i + 1, r);
            for(int k = 0; k < lv.size(); k++){
                for(int j = 0; j < rv.size(); j++){
                    auto t = new TreeNode(i);
                    t -> left = lv[k];
                    t -> right = rv[j];
                    v.push_back(t);
                }
            }
        }
        return v;
    }
};
