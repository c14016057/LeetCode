#include <iostream>
#include <vector>
#include <string>
#include "Bt.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
   		vector<vector<int>> ans;
		vector<int> buf;
		srchAll(root, sum, ans, buf);
		return ans;
  	}
	void srchAll(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& buf) {
		if (root == NULL)
			return;
		if (!(root->left || root->right))
			if (sum == root->val) {
				buf.push_back(root->val);
				ans.push_back(buf);
				buf.pop_back();
				return;
			}
			else 
				return;
		buf.push_back(root->val);
		srchAll(root->left, sum-root->val, ans, buf);
		srchAll(root->right, sum-root->val, ans, buf);
		buf.pop_back();
		return;

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
	vector<vector<int>> ans = sol.pathSum(bt.getTree(), S);
	for (vector<int> vec: ans) {
		for (int num: vec)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}
