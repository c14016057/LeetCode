/*dp solution

1. maintain dp table 
	-bool match(i, j): returns true if p[0:i] matchs s[0:j] otherwise returns false.
1.1. dp formulation
	-match(i,j) = 0, if p[i]!=s[j].
				= match(i-1, j) || match(i-1, j-1), if p[i] == *
				= match(i-1, j-1), if p[i] == s[j] || p[i] == ?. 

*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
		int slen = s.size();
		//dp
		bool dp[p.size()+1][s.size()+1];
		for (int i = 0; i < p.size()+1; i++)
			if (i == 0)
				dp[i][0] = true;
			else if (p[i-1] >= 'a' && p[i-1] <= 'z')
				dp[i][0] = false;
			else if (p[i-1] == '?')
				dp[i][0] = false;
			else
				dp[i][0] = dp[i-1][0];
		for (int i = 1; i < s.size()+1; i++)
			dp[0][i] = false;
		for (int i = 1; i < p.size()+1; i++)
			for (int j = 1; j < s.size()+1; j++)
				if (myequal(s[j-1], p[i-1])) {
					if ((p[i-1] >= 'a' && p[i-1] <= 'z') || p[i-1] == '?')
						dp[i][j] = dp[i-1][j-1];
					else
						dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
				}
				else if (p[i-1] >= 'a' && p[i-1] <= 'z')
					dp[i][j] = false;
				//else
				//	dp[i][j] = dp[i-1][j];

		//print table
		cout <<"  O";
		for (int i = 0; i < s.size(); i++)
			cout << " " << s[i];
		cout << endl;
		for (int i = 0; i < p.size()+1; i++) {
			if (i == 0)
				cout << "O";
			else
				cout << p[i-1];
			for (int j = 0; j < s.size()+1; j++) 
				cout << " " << dp[i][j];
			cout << endl;
		}
	return dp[p.size()][s.size()];
	}
private:
	bool myequal(char s, char p) {
		if (p == '?' || p == '*') return true;
		if (p == s) return true;
		return false;
	}
};
int main() {
	string s, p;
	cin >> s >> p;
	Solution sol;
	sol.isMatch(s, p);
	return 0;
}
