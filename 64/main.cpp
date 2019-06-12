#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0)
			return 0;
		int col = grid[0].size();
		vector<vector<int>> dp(row+1, vector<int>(col+1));
		for (int i = 2; i < row+1; i++)
			dp[i][0] = 2147483647;
		for (int j = 2; j < col+1; j++)
			dp[0][j] = 2147483647;
		for (int i = 1; i < row+1; i++)
			for (int j = 1; j < col+1; j++)
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
		return dp[row][col];
	}
};
int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<int>> grid(row, vector<int>(col));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> grid[i][j];
	Solution sol;
	cout << sol.minPathSum(grid) << endl;
	return 0;
}
