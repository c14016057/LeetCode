#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		s = to_string(x);
		len = s.size();
		for (int i = 0; i < len/2; i++)
			if (s[i] != s[len-1-i])
				return false;
		return true;
	}
private:
	int len;
	string s;
};

int main() {
	int N;
	Solution Sol;
	cin >> N;
	cout << Sol.isPalindrome(N) << endl;
	return 0;
}
