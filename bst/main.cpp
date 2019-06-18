#include <iostream>
#include "Bst.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> val(N);
	for (int i = 0; i < N; i++) 
		cin >> val[i];
	Bst bst(val);
	bst.printTree();
	TreeNode *t1 = bst.searchNode(1);
	TreeNode *t2 = bst.searchNode(3);
	std::swap(t1->val, t2->val);
	bst.printTree();
	return 0;
}
