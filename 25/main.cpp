#include <iostream>
#include "LinkList.h"
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *oldhead = head, *befnode = NULL, *nextnode = head;
		if (!head)
			return NULL;
		int nk = k;
		while(nk) {
			if (!nextnode)
				break;
			ListNode *curnode = nextnode;
			nextnode = curnode->next;
			curnode->next = befnode;
			befnode = curnode;
			nk--;
		}
		if (nk>0) 
			return reverseKGroup(befnode, k-nk);
		else 
			oldhead->next = reverseKGroup(nextnode, k);
		return befnode;
			
	}
};
int main() {
	int N, k;
	cin >> N >> k;
	vector<int> vec;
	while(N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	ListNode *list = LinkList::NewList(vec);
	LinkList::PrintList(list);
	Solution sol;
	LinkList::PrintList(sol.reverseKGroup(list, k));
	return 0;
}
