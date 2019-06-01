#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		if (l3!=(l1+l2))
			return false;
		vector<vector<bool>> dp(l1+1, vector<bool>(l2+1));
		dp[0][0] = true;
		for (int i = 1; i < l1+1; i++)
			if (dp[i-1][0] && s3[i-1] == s1[i-1])
				dp[i][0] = true;
			else
				dp[i][0] = false;
		for (int i = 1; i < l2+1; i++)
			if (dp[0][i-1] && s3[i-1] == s2[i-1])
				dp[0][i] = true;
			else
				dp[0][i] = false;
		for (int i = 1; i < l1+1; i++)
			for (int j = 1; j < l2+1; j++) {
				if (s1[i-1] == s3[i+j-1])
					dp[i][j] = (dp[i][j] || dp[i-1][j]);
				if (s2[j-1] == s3[i+j-1])
					dp[i][j] = (dp[i][j] || dp[i][j-1]);
			}
		return dp[l1][l2];
	
	}
};
int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution sol;
	cout << sol.isInterleave(s1, s2, s3) << endl;
	return 0;
}
