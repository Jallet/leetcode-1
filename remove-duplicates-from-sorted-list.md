``` cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !(head -> next)) return head;
        int c = head -> val;
        ListNode* p = head -> next, *q = head;
        while(p){
            if(p -> val == c){
                q -> next = p -> next;
                p = q -> next;
                continue;
            }
            q = p;
            p = q -> next;
            c = q -> val;
        }
        return head;
    }
};
```
