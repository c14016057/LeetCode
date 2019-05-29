#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
		int len = s1.size();
		if (len == 1)
			return s1[0] == s2[0];
		//Cutting edges for recursive tree.
		if (s1.compare(s2) == 0)
			return true;
		//Another cutting edges for recursive tree.
		int s1hash[26] = {};
		int s2hash[26] = {};
		for (int i = 0; i < len; i++) {
			s1hash[s1[i]-'a']++;
			s2hash[s2[i]-'a']++;
		}
		if (memcmp(s1hash, s2hash, sizeof s1hash) !=0)
			return false;

		for (int i = 1; i <= len-1; i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i))&&
			    isScramble(s1.substr(i, len-i ),s2.substr(i, len-i )))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len-i, i))&&
			    isScramble(s1.substr(i, len-i ),s2.substr(0, len-i )))
				return true;
		}
		return false;

		/* dp solution
		int len = s1.size();
		vector<vector<vector<bool>>> dp(len+1, vector<vector<bool>>(len, vector<bool>(len, false)));
		for (int p1 = 0; p1 < len; p1++)
			for (int p2 = 0; p2 < len; p2++)
				dp[1][p1][p2] = s1[p1] == s2[p2];
		for (int l = 2; l <= len; l++) 
			for (int p1 = 0; p1 <= len-l; p1++)
				for (int p2 = 0; p2 <= len-l; p2++) {
					if (s1.substr(p1,l).compare(s2.substr(p2,l))==0) {
						dp[l][p1][p2] = true;
						continue;
					}
					int counts1[26] = {};
					int counts2[26] = {};
					for (int tr = 0; tr < l; tr++) {
						counts1[s1[p1+tr]-'a']++;
						counts2[s2[p2+tr]-'a']++;
					}
					if (memcmp(counts1, counts2, sizeof counts1)!=0) {
						dp[l][p1][p2] = false;
						continue;
					}
					
					bool isOk = false;
					for (int piv = 1; piv < l; piv++) {
						isOk |= (dp[piv][p1][p2] && dp[l-piv][p1+piv][p2+piv]);
						isOk |= (dp[piv][p1][p2+l-piv] && dp[l-piv][p1+piv][p2]);
						if (isOk)
							break;
					}
					dp[l][p1][p2] = isOk;
				}
		return dp[len][0][0];
	*/	
	}
};
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	Solution sol;
	cout << sol.isScramble(s1, s2) << endl;
	return 0;
}
