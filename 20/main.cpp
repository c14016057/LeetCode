#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) { 
	int slen = s.size();
	vector<char> stack;
	for (int i = 0; i < slen; i++) {
		if (s[i] == '('||s[i] == '{'||s[i]=='[') {
			stack.push_back(s[i]);
		}
		else {
			if (stack.size() == 0)
				return false;
			if (abs(s[i]-stack[stack.size()-1])>3)
				return false;
			stack.pop_back();
		}
	}
	if (stack.size()>0)
		return false;
	return true;
	}
};
int main() {
	string s;
	cin >> s;
	Solution sol;
	cout << sol.isValid(s) << endl;
	return 0;
}

