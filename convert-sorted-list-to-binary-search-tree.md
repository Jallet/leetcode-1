``` cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) return NULL;
        int l = 1;
        ListNode* cur = head;
        while(cur -> next){
            l++;
            cur = cur -> next;
        }
        return helper(head, 0, l - 1);
    }
    
    TreeNode *helper(ListNode* &p, int start, int end){
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* left = helper(p, start, mid - 1);
        TreeNode* parent = new TreeNode(p -> val);
        parent -> left  = left;
        p = p -> next;
        parent -> right = helper(p, mid + 1, end);
        return parent;
    }
};
```
