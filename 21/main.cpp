#include "LinkList.h"
using namespace std;
class Solution {
public:
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
		return ret->next;
	}
};
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> vec_n, vec_m;
	while(N--) {
		int temp;
		cin >> temp;
		vec_n.push_back(temp);
	}
	while(M--) {
		int temp;
		cin >> temp;
		vec_m.push_back(temp);
	}
	ListNode *list_n = LinkList::NewList(vec_n);
	ListNode *list_m = LinkList::NewList(vec_m);
	Solution sol;
	ListNode *ans = sol.mergeTwoLists(list_n, list_m);
	LinkList::PrintList(ans);
	return 0;
}
