#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));//m*n
		for (int i = 0; i < m; i++)
			dp[i][0] = 1;
		for (int i = 0; i < n; i++)
			dp[0][i] = 1;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		/*for (vector<int> row: dp) {
			for (int col: row)
				cout << col << " ";
			cout << endl;
		}*/
		return dp[m-1][n-1];
	}
};
int main() {
	int m, n;
	cin >> m >> n;
	Solution sol;
	cout << sol.uniquePaths(m, n);
	return 0;
}
