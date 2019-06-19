#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		int num = wordDict.size();
		vector<bool> dp(len+1);
		dp[0] = true;
		for (int i = 1; i <= len; i++) {
			int start = len - i;
			dp[i] = false;
			for (int j = 0; j < num; j++) {
				int wordlen = wordDict[j].size();
				if (wordlen <= i)
					if (s.substr(start, wordlen) == wordDict[j])
						if (dp[i-wordlen]) {
							dp[i] = true;
							break;
						}
			}
		}
		return dp[len];
	}
};
int main() {
	int N;
	string s;
	vector<string> wordDict;
	cin >> N;
	cin >> s;
	while(N--) {
		string temp;
		cin >> temp;
		wordDict.push_back(temp);
	}
	Solution sol;
	cout << sol.wordBreak(s, wordDict);
	return 0;
}
