#include <iostream>
#include <vector>
#include <string>
#include "Bt.h"
using namespace std;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if (root == NULL)
			return false;
		if (!(root->left || root->right))
			if (sum == root->val)
				return true;
			else
				return false;
		return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
int main() {
	int N, S;
	cin >> N >> S;
	vector<string> vec;
	vec.push_back("-");
	while(N--) {
		string temp;
		cin>> temp;
		vec.push_back(temp);
	}
	Bt bt(vec);
	Solution sol;
	cout << sol.hasPathSum(bt.getTree(), S) << endl;
	return 0;
}
