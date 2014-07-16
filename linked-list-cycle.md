[https://oj.leetcode.com/problems/linked-list-cycle/](https://oj.leetcode.com/problems/linked-list-cycle/)

``` cpp
#include <iostream>
using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head || !(head->next) || !(head->next->next))
			return false;

		ListNode* p = head->next, *q = head->next->next;
		while (q->next && q->next->next)
		{
			p = p->next;
			q = q->next->next;
			if (p == q)
			{
				return true;
			}
		}
		return false;
	}
};
int main()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);

	a.next = &b;
	b.next = &c;
	Solution s;
	cout << s.hasCycle(&a) << endl;
	return 0;
}
```
