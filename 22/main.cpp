#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string ans(2*n, ' ');
		rc(ret, ans, 0, 2*n, n, 0);
		return ret;
	}
private:
	void rc(vector<string>& ret, string& ans, int idx, int n, int l, int r) {
		if (idx == n) {
			ret.push_back(ans);
			return;
		}
		if (l > 0) {
			ans[idx] = '(';
			rc(ret, ans, idx+1, n, l-1, r+1);
		}
		if (r > 0) {
			ans[idx] = ')';
			rc(ret, ans, idx+1, n, l, r-1);
		}
		return;
	}
};
int main() {
	int n;
	cin >> n;
	Solution sol;
	vector<string> ans = sol.generateParenthesis(n);
	for (string s: ans)
		cout << s << endl;
	return 0;
}
