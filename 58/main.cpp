#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
		int len = s.size();
		int count = 0, oldcount = 0;
		for (int i = 0; i < len; i++)
			if (s[i] == ' ') {
				if (count != 0)
					oldcount = count;
				count = 0;
			}
			else
				count++;
		return count == 0 ? oldcount : count;
	}
};
int main() {
	string s;
	std::getline(std::cin, s);
	Solution sol;
	cout << sol.lengthOfLastWord(s);
	return 0;
}
