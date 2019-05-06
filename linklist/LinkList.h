#ifndef MyLinkList
#define MyLinkList
#include <vector>
#include <iostream>
using namespace std;


///////////////////////////////
//    ListNode definition    //
///////////////////////////////
typedef struct ListNode { 
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
} ListNode;
///////////////////////////////
//       Class definition    //
///////////////////////////////
class LinkList {
public:
	ListNode* NewList(vector<int>& vec) {
		ListNode *head = new ListNode(0), *nextlink;
		nextlink = head;
		for (int i = 0; i < vec.size(); i++) {
			ListNode *newnode = new ListNode(vec[i]);
			nextlink->next = newnode;
			nextlink = newnode;
		}
		nextlink->next = NULL;
		ListNode *ret = head->next;
		delete head;
		return ret;
	}
	void PrintList(ListNode* list) {
		while(list) { 
			cout << list->val << " ";
			list = list->next;
		}
		cout << endl;
	}
};
#endif
