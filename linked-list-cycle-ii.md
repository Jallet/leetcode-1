[https://oj.leetcode.com/problems/linked-list-cycle-ii/](https://oj.leetcode.com/problems/linked-list-cycle-ii/)
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !(head->next) || !(head->next->next))
			return NULL;

		ListNode *p = head ->next, *q = head->next->next;
		while (q ->next && q ->next ->next)
		{
			if (p == q)
				break;
			p = p->next;
			q = q->next->next;
		}

		if (q->next == NULL || q->next->next == NULL)
			return NULL;

		p = head;
		while (p != q)
		{
			p = p->next;
			q = q->next;
		}
		return p;
    }
};
```
