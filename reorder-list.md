[https://oj.leetcode.com/problems/reorder-list/](https://oj.leetcode.com/problems/reorder-list/)

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
    ListNode* reverseList(ListNode* head)
	{
		ListNode *p = head, *q = head ->next;
		head->next = NULL;
		ListNode *t = NULL;
		while (q)
		{
			t = q->next;
			q->next = p;
			p = q;
			q = t;
		}
		return p;
	}


	void reorderList(ListNode* head)
	{
		if (!head || !(head->next) || !(head->next->next))
			return;
		ListNode* p = head, *q = head;
		while (q ->next && q->next->next)
		{
			p = p->next;
			q = q->next->next;
		}
		q = reverseList(p->next);
		p->next = NULL;
		p = head;
		ListNode *t = NULL, *tt = q ->next;
		while (q)
		{
			t = p->next;
			p->next = q;
			tt = q->next;
			p = p ->next;
			p->next = t;
			p = t;
			q = tt;
		}
	}
};

```
