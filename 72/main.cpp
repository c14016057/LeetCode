#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
		int l1 = word1.size(), l2 = word2.size(), maxl = max(l1, l2); 
		vector<vector<int>> dp(l1+1, vector<int>(l2+1));
		for (int i = 1; i < l1+1; i++)
			dp[i][0] = i;
		for (int j = 1; j < l2+1; j++)
			dp[0][j] = j;
		for (int i = 1; i < l1+1; i++)
			for (int j = 1; j < l2+1; j++) {
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1])+1;
			}
		/*
		cout << "    ";
		for (char c: word2)
			cout << c << " ";
		cout << endl;
		int idx = -1;
		for (vector<int> row:dp) {
			if (idx>=0)
				cout << word1[idx] << " ";
			else
				cout << "  ";
			idx++;
			for (int col: row)
				cout << col << " ";
			cout << endl;
		}
		*/
		return dp[l1][l2];
	}
};
int main() {
	string w1, w2;
	cin >> w1 >> w2;
	Solution sol;
	cout <<sol.minDistance(w1, w2);
	return 0;
}
