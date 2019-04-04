/*dp solution

1. first extend * to specific numbers of characters in p, the extend length = the max length appear in s.
1.1 mark the characters in p which are not be extended. 
2. maintain dp table 
	-bool match(i, j): returns true if p[0:i] matchs s[0:j] otherwise returns false.
2.1. dp formulation
	-match(i,j) = 0, if p[i]!=s[j] and p[i] is marked.
				= match(i-1, j), if p[i]!=s[j] and p[i] is not marked. 
				= match(i-1, j-1), if p[i] == s[j]. 

*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
		int slen = s.size();
		// maintain maxlen
		int maxlen[26] = {0};
		char c;
		if (slen != 0)
			c = s[0];
		int count = 1;
		for (int i = 1; i < slen; i++) {
			if (s[i]!=c) {
				maxlen[c-'a'] = maxlen[c-'a'] > count ? maxlen[c-'a'] : count;
				count = 1;
				c = s[i];
			}
			else 
				count++;
		}
		if (slen != 0)
			maxlen[c-'a'] = maxlen[c-'a'] > count ? maxlen[c-'a'] : count;
		// extend p
		int pt = 0;
		while(pt < p.size()) {
			if (pt == p.size()-1) {
				p[pt] = mark(p[pt]);
				pt++;
			}
			else if (p[pt+1] == '*'){
				int mlen;
				if (p[pt] == '.') {
					mlen = slen;
					string getExS(mlen, '.');
					p.insert(pt+1, getExS);
				}
				else {
					mlen = maxlen[p[pt] - 'a'];
					string getExS(mlen, p[pt]);
					p.insert(pt+1, getExS);
				}
				p.erase(p.begin()+pt+1+mlen);
				p.erase(p.begin()+pt);
				pt = pt+mlen;
			}
			else {
				p[pt] = mark(p[pt]);
				pt++;
			}
		}
		//dp
		int dp[p.size()+1][s.size()+1];
		for (int i = 0; i < p.size()+1; i++)
			if (i == 0)
				dp[i][0] = 1;
			else if (p[i-1] < 'a' && p[i-1] != '.')
				dp[i][0] = 0;
			else
				dp[i][0] = dp[i-1][0];
		for (int i = 1; i < s.size()+1; i++)
			dp[0][i] = 0;
		for (int i = 1; i < p.size()+1; i++)
			for (int j = 1; j < s.size()+1; j++)
				if (myequal(s[j-1], p[i-1])) {
					if (p[i-1] < 'a' || p[i-1] != '.')
						dp[i][j] = dp[i-1][j-1];
					else
						dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])>0;
				}
				else if (p[i-1] < 'a')
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i-1][j];

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

	if (dp[p.size()][s.size()] == 1) return true;
	return false;
	}
private:
	char mark(char c) {
		if (c == '.') return '+';
		return c - 'a'+'A';
	}
	bool myequal(char s, char p) {
		if (p == '.' || p == '+') return true;
		if (p == s) return true;
		if (p-'A'+'a' == s) return true;
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
