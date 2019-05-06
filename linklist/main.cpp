#include "LinkList.h"
#include <iostream>
int main() {
	vector<int> vec = {1, 2, 3, 4};
	LinkList obj;
	ListNode *list = obj.NewList(vec);
	obj.PrintList(list);
	return 0;

}
