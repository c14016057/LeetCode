#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
		std::size_t p = haystack.find(needle);
		if (p!=std::string::npos)
			return (int)p;
		return -1;
	}
};
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	Solution sol;
	cout << sol.strStr(s1, s2);
	return 0;
}
