#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) { 
		int stack = 0, max = 0, l = 0;
		int len = s.size();
		for (int i = 0 ; i < len; i++) {
			if (s[i] == ')') {
				stack--;
				if (stack < 0) {
					max = max > i-l ? max : i-l;
					stack = 0;
					l = i+1;
				}
			}
			else
				stack++;
		}
		if (stack == 0) 
			max = max > len-l ? max : len-l;
		int r = len-1;
		stack = 0;
		for (int i = len-1 ; i >= l; i--) {
			if (s[i] == '(') {
				stack--;
				if (stack < 0) {
					max = max > r-i ? max : r-i;
					stack = 0;
					r = i-1;
				}
			}
			else
				stack++;
		}
		if (stack == 0) 
			max = max > r-l+1 ? max : r-l+1;
		return max;
	}
};
int main() {
	string s;
	cin >> s;
	Solution sol;
	cout << sol.longestValidParentheses(s);
	return 0;
}
