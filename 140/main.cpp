#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
		vector<vector<string>> ans;
		vector<string> find;
		search(len, ans, find, s, wordDict, dp);
		vector<string> ret;
		for (vector<string> each: ans) {
			int numsword = each.size();
			string newans;
			for (int i = 0; i < numsword; i++) {
				newans += each[i];
				if (i!=numsword-1)
					newans += " ";
			}
			ret.push_back(newans);
		}
		return ret;
	}
private:
	void search(int len, vector<vector<string>>& ans, vector<string>& find,
				string& s, vector<string>& wordDict, vector<bool>& dp) {
		if (len == 0) {
			ans.push_back(find);
			return;
		}
		int nums = wordDict.size(), slen = s.size(), start = slen - len;
		for (int i = 0; i < nums; i++) {
			int wordlen = wordDict[i].size();
			string word = wordDict[i];
			if (wordlen <= len)
				if (s.substr(start, wordlen) == word && dp[len-wordlen]) {
					find.push_back(word);
					search(len-wordlen, ans, find, s, wordDict, dp);
					find.pop_back();
				}
		}
		return;
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
	vector<string> ans = sol.wordBreak(s, wordDict);
	for (string each: ans)
		cout << each << endl;
	return 0;
}
