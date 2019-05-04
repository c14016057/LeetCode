#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (n == 0)
			return "";
		int minlen = 2147483647;
		for (int i = 0; i < n; i++) {
			int strlen = strs[i].size(); 
			minlen = min(minlen, strlen);
		}
		int i = 0;
		for (; i < minlen; i++) {
			int j = 1;
			for (; j < n; j++)
				if (strs[j][i]!=strs[j-1][i])
					break;
			if (j != n)
				break;	
		}
		return strs[0].substr(0, i);
	}
};
int main() {
	vector<string> strs;
	int N;
	cin >> N;
	while(N--) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	Solution sol;
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
