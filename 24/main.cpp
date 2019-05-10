#include <iostream>
#include "LinkList.h"
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode *ret = new ListNode(0), *p1 = head, *p2, *p3, *bef = ret;
		ret->next = head;
		while(p1) {
			if (!p1->next) {
				bef->next = p1;
				break;
			}
			else {
				p2 = p1->next;
				p3 = p1->next->next;
				p1->next = p3;
				p2->next = p1;
				bef->next = p2;
				bef = p1;
				p1 = p3;
			}
		}
		return ret->next;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec;
	while(N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	ListNode* list = LinkList::NewList(vec);
	LinkList::PrintList(list);
	Solution sol;
	ListNode* newlist = sol.swapPairs(list);
	LinkList::PrintList(newlist);
	return 0;
}
