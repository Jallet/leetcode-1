[https://oj.leetcode.com/submissions/detail/8299909/](https://oj.leetcode.com/submissions/detail/8299909/)

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
    ListNode *insertionSortList(ListNode *head) {
		if (!head)
			return NULL;

		int i = 0;
		ListNode * p = head;
		ListNode * head2 = head;
		ListNode *pre = head, *pre2 = NULL;

		head = head->next;

		while (head){
			i++;
			int j = 0;
			head2 = p;
			pre2 = NULL;
			bool swap = false;
			while (j < i && head)
			{
				if (head->val < head2->val && pre2 != NULL)
				{
					pre->next = head->next;
					head->next = head2;
					pre2->next = head;
					head = pre->next;
					swap = true;
					break;
				}
				else if (head->val < head2->val && pre2 == NULL)
				{
					pre->next = head->next;
					head->next = head2;
					head2 = head;
					p = head;
					head = pre->next;
					swap = true;
					break;
				}

				pre2 = head2;
				head2 = head2->next;
				j++;
			}
			if (!swap){
				pre = head;
				head = head->next;
			}
		}
		return p;
	
 
    }
};
```
