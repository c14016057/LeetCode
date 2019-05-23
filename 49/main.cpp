#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
		int idx = 0;
		vector<vector<string>> ret;
		unordered_map<string, int> hs_table;
		for (int i = 0; i < strs.size(); i++) {
			string key = strs[i];
			std::sort(key.begin(), key.end());
			if (hs_table.count(key)) {
				ret[hs_table[key]].push_back(strs[i]);
			}
			else {
				hs_table[key] = idx;
				idx++;
				vector<string> temp;
				temp.push_back(strs[i]);
				ret.push_back(temp);
			}
		}
		return ret;
	}
};
int main() {
	int N;
	cin >> N;
	vector<string> strs;
	while(N--) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	Solution sol;
	auto ans = sol.groupAnagrams(strs);
	for (vector<string> v : ans) {
		for (string s: v)
			cout << s << " ";
		cout << endl;
	}
	return 0;
}
