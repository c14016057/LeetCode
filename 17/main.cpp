#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		int diglen = digits.size();
		string ans(diglen, 'a');
		vector<string> ret;
		if (diglen == 0)
			return ret;
		rc(0, diglen, ret, digits, ans);
		return ret;
	}
private:
	vector<vector<char>> tb = {{97, 98, 99}, {100, 101, 102}, {103, 104, 105}, {106, 107, 108}, {109, 110, 111}, {112, 113, 114, 115}, {116, 117, 118}, {119, 120, 121, 122}};
	void rc(int idx, int diglen, vector<string>& ret, string& digits, string& ans) {
		if (idx == diglen) {
			ret.push_back(ans);
			return;
		}
		int num = digits[idx]-'2';
		int len = tb[num].size();
		for (int i = 0; i < len; i++) {
			ans[idx] = tb[num][i];
			rc(idx+1, diglen, ret, digits, ans);
		}
		return;
	}
};
int main() {
	string digits;
	cin >> digits;
	Solution sol;
	vector<string> ans = sol.letterCombinations(digits);
	for (string s : ans)
		cout << s << endl;
}
