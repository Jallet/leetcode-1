``` cpp
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **p = &head;

        while (*p && (*p)->next) {
            ListNode *t = (*p)->next;

            (*p)->next = t->next;
            t->next = *p;
            *p = t;

            p = &(*p)->next->next;
        }

        return head;
    }
};
```
