#include "LinkList.h"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode*> listP;
		ListNode* ret = head;
		while(head) {
			listP.push_back(head);
			head = head->next;
		}
		int target = listP.size() - n -1;
		if (target < 0) {
			ret = ret->next;
			delete listP[0];
		}
		else if (target == listP.size()-1)
			return ret;
		else {
			listP[target]->next = listP[target+1]->next;
			delete listP[target+1];
		}
		return ret;
	}
};
int main() {
	LinkList list;
	int	N, n;
	cin >> N >> n;
	vector<int> nums;
	while(N--) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	ListNode *head = list.NewList(nums);
	list.PrintList(head);

	Solution sol;
	ListNode *newhead = sol.removeNthFromEnd(head, n);
	list.PrintList(newhead);
	return 0;

}
