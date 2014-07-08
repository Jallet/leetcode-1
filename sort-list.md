[https://oj.leetcode.com/submissions/detail/8262514/](https://oj.leetcode.com/submissions/detail/8262514/)


用merge sort写的链表排序，时间244ms
``` cpp
#include <iostream>
using namespace std;
struct ListNode{
	ListNode(int a) :val(a), next(NULL){}

	int val;
	ListNode * next;
};

class Solution
{
public:
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL)
			return NULL;

		int len = 0;
		ListNode* phead = head;
		while (phead){
			len++;
			phead = phead->next;
		}

		if (len < 2)
			return head;

		if (len == 2){
			if (head->val > head->next->val){
				head->next -> next= head;
				head = head ->next;
				head->next->next = NULL;
			}
			return head;
		}

		int cur = 0;
		ListNode *secondHead = head;
		ListNode* setNULL = NULL;

		while (cur < len / 2){
			cur++;
			setNULL = secondHead;
			secondHead = secondHead->next;
		}

		setNULL->next = NULL;
		secondHead = this->sortList(secondHead);
		head = this->sortList(head);
		phead = NULL;
		ListNode *papa = NULL;

		while (secondHead || head)
		{
			if (!secondHead){
				phead->next = head;
				head = NULL;
			}
			else if (!head)
			{
				phead->next = secondHead;
				secondHead = NULL;
			}
			else{
				if (phead == NULL){
					if (head->val <= secondHead->val)
					{
						phead = head;
						head = head->next;
					}
					else{
						phead = secondHead;
						secondHead = secondHead->next;
					}
					papa = phead;
					phead->next = NULL;
				}
				else{
					if (head->val <= secondHead->val)
					{
						phead->next = head;
						head = head->next;
					}
					else{
						phead->next = secondHead;
						secondHead = secondHead->next;
					}
					phead = phead->next;
				}

			}

		}

		return papa;
	}

};

int main(){
	ListNode a(2);
	ListNode b(22);
	ListNode c(322);
	ListNode d(7);

	a.next = &b;
	b.next = &c;
	c.next = &d;

	Solution s;
	ListNode *p = s.sortList(&a);
	while (p){
		cout << p->val << endl;
		p = p->next;
	}

	return 0;
}

```

同样的方法，python。。。需要6000ms。。。。
