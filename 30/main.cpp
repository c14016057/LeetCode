//not my code. Reference to https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13656/An-O(N)-solution-with-detailed-explanation
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ret;
		int wordscount = words.size(), slen = s.size();
		if (wordscount == 0 || slen == 0)
			return ret;
		int wordslen = words[0].size();
		unordered_map<string, int> dict;
		for (int i = 0; i < wordscount; i++)
			dict[words[i]]++;
		for (int i = 0; i < wordslen; i++) {
			int start = i, count = 0;
			unordered_map<string, int> wdict;
			for (int j = i; j < slen; j+=wordslen) {
				string tar = s.substr(j, wordslen);
				if (dict.count(tar) > 0) {
					wdict[tar]++;
					count++;
					if (wdict[tar] <= dict[tar]) {
						if (count == wordscount) {
							ret.push_back(start);
							string eraseWord = s.substr(start, wordslen);
							wdict[eraseWord]--;
							start += wordslen;
							count--;
						}
					}
					else {
						while (wdict[tar] > dict[tar]) {
							string eraseWord = s.substr(start, wordslen);
							wdict[eraseWord]--;
							start += wordslen;
							count--;
						}
					}
				}
				else {
					wdict.clear();
					count = 0;
					start = j + wordslen;
				}
			}
		}
		return ret;
	}
};
int main() {
	string s;
	int N;
	vector<string> words;
	cin >> s >> N;
	while(N--) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	Solution sol;
	vector<int> ans = sol.findSubstring(s, words);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
