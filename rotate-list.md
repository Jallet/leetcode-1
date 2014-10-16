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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode* p = head, *pp = head, *q = head, *qq = head;;
        int i = k;
        int l = 0;
        while(p != nullptr){
            p = p -> next;
            l++;
        }
        p = head;
        
        i = k % l;
        if(!i) return head;
        
        while(i--){
            q = p;
            p = p -> next;
        } 
        
        while(p != NULL){
            q = p;
            p = p -> next;
            qq = pp;
            pp = pp -> next;
        }
        q -> next = head;
        qq -> next = NULL;
        q = pp -> next;
        return pp;
    }
};
```
