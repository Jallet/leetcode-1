[https://oj.leetcode.com/problems/add-two-numbers/](https://oj.leetcode.com/problems/add-two-numbers/)

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3 = NULL, *cur = NULL;
        int carry = 0;
        while (l1 || l2) {
          if (l1) {
            carry += l1->val;
            l1 = l1->next;
          }
          if (l2) {
            carry += l2->val;
            l2 = l2->next;
          }
          auto x = new ListNode(carry%10);
          carry /= 10;
          if (! l3)
            l3 = cur = x;
          else {
            cur->next = x;
            cur = cur->next;
          }
        }
        if (carry)
          cur->next = new ListNode(carry);
        return l3;
    }
};
```
