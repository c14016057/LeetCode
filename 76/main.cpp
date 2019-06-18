#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
		vector<int> countS(256), countT(256);
		int fitS = 0, fitT = 0;
		int l = 0, r = 0;
		int ansl = 0, ansr = 0;
		int slen = s.size();
		int Minlen = 2147483647;
		fitT = fit(t, countT);
		while (true) {
			if (r < slen && fitS < fitT) {
				countInsert(s[r], countS, fitS, countT);
				r++;
			}
			else if (fitS == fitT) {
				if (r-l < Minlen) {
					Minlen = r - l;
					ansr = r;
					ansl = l;
				}
				countDelete(s[l], countS, fitS, countT);
				l++;
			}
			else
				break;
		}
		return s.substr(ansl, ansr-ansl);

	}
private:
	int fit(string& s, vector<int>& count) {
		for (char c: s)
			count[c]++;
		return s.size();
	}
	void countInsert (char s, vector<int>& countS, int& fitS, vector<int>& countT) {
		int idx = s;
		if (countT[idx] == 0)
			return;
		if (countS[idx] < countT[idx])
			fitS++;
		countS[idx]++;
		return;
	}
	void countDelete (char s, vector<int>& countS, int& fitS, vector<int>& countT) {
		int idx = s;
		if (countT[idx] == 0)
			return;
		if (countS[idx] <= countT[idx])
			fitS--;
		countS[idx]--;
		return;
	}
};
int main() {
	string s, t;
	cin >> s >> t;
	Solution sol;
	cout << sol.minWindow(s, t) << endl;
	return 0;
}
