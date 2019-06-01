#include <iostream>
#include <vector>
#include "LinkList.h"
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		vector<ListNode*> nodeArr;
		while(head) {
			nodeArr.push_back(head);
			head = head->next;
		}
		int len = nodeArr.size();
		if (len == 0)
			return head;
		k = k%len;
		if (k == 0)
			return nodeArr[0];
		int newhead = len - k;
		nodeArr[len-1] -> next = nodeArr[0];
		nodeArr[newhead-1] -> next = NULL;
		return nodeArr[newhead];
	}
};
int main() {
	int N, k;
	cin >> N >> k;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	ListNode* list = LinkList::NewList(vec);
	Solution sol;
	ListNode* newlist = sol.rotateRight(list, k);
	LinkList::PrintList(newlist);
	return 0;
}
