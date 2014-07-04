https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

SB解法：
``` python
# Definition for singly-linked list.
class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
  # @return a ListNode
  def removeNthFromEnd(self, head, n):
    stack = []
    count = 0
    while head != None:
      stack.append(head)
      head = head.next

    prev = None
    while len(stack):
      count = count + 1
      i = stack.pop()
      if count != n:
        i.next = prev
        prev = i
        head = i
    return head

if __name__ == '__main__':
  a = ListNode(1)
  b = ListNode(2)
  c = ListNode(3)
  a.next = b
  b.next = c

  s = Solution()
  head = s.removeNthFromEnd(a, 3)
  while head:
    print(head.val)
    head = head.next

```
O(n)复杂度的解法：

``` cpp
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode **x = &head, *y = head;
		while (n--) y = y->next;
		while (y) {
			x = &(*x)->next;
			y = y->next;
		}
		y = (*x)->next;
		//delete *x
		*x = y;
		return head;
	}
};

```
        








      
        
