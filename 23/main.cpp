#include <iostream>
#include "LinkList.h"
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		return mymerge(lists, 0, lists.size()-1);
	}
private:
	ListNode* mymerge(vector<ListNode*>& lists, int l, int r) {
		if (l > r)
			return NULL;
		if (r == l)
			return lists[r];
		if (r - l == 1)
			return mergeTwoLists(lists[l], lists[r]);
		int k = (r + l)/2;
		ListNode *llist = mymerge(lists, l, k);
		ListNode *rlist = mymerge(lists, k+1, r);
		return mergeTwoLists(llist, rlist);
	}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *ret = new ListNode(0), *cur = ret;
		while(l1&&l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				cur = cur->next;
				l1 = l1->next;
			}
			else {	
				cur->next = l2;
				cur = cur->next;
				l2 = l2->next;
			}
		}
		if (l1!=NULL)
			cur->next = l1;
		else if(l2!=NULL)
			cur->next = l2;
		ListNode *newret = ret->next;
		delete ret;
		return newret;
	}

};
int main() {
	int N;
	vector<vector<int>> vecs;
	vector<ListNode*> lists;
	cin >> N;
	while(N--) {
		int len;
		vector<int> tempvec;
		cin >> len;
		while(len--) {
			int temp;
			cin >> temp;
			tempvec.push_back(temp);
		}
		vecs.push_back(tempvec);
	}
	for (int i = 0; i < vecs.size(); i++) {
		ListNode *templist = LinkList::NewList(vecs[i]);
		lists.push_back(templist);
	}
	for (int i = 0; i < lists.size(); i++)
		LinkList::PrintList(lists[i]);
	Solution sol;
	ListNode *res = sol.mergeKLists(lists);
	LinkList::PrintList(res);
	return 0;
}
	
