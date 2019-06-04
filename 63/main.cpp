#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(vector<vector<int>>& Grid) {
		int m =	Grid.size();
		if (m == 0)
			return 0;
		int n = Grid[0].size();
		if (n == 0)
			return 0;
		if (Grid[0][0] == 1)
			return 0;
		vector<vector<long long>> dp(m, vector<long long>(n));
		dp[0][0] = 1;
		for (int i = 1; i < m; i++)
			if (Grid[i][0])
				dp[i][0] = 0;
			else {
				dp[i][0] = dp[i-1][0];
			}
		for (int i = 1; i < n; i++)
			if (Grid[0][i])
				dp[0][i] = 0;
			else {
				dp[0][i] = dp[0][i-1];
			}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++) 
				if (Grid[i][j])
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
		return dp[m-1][n-1];
	}
};
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n));
	for (int i = 0 ; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];
	Solution sol;
	cout << sol.uniquePaths(grid);
	return 0;
}
