#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int move[4][6] = {{ 0, 1, 0, 0, 1, 0}, 
						  { 1, 0, 0,-1, 0, 0}, 
						  { 0,-1, 0, 0, 0,-1}, 
						  {-1, 0, 1, 0, 0, 0}};//r c l r u d
		vector<int> ret;
		int row = matrix.size();
		if (row == 0)
			return ret;
		int col = matrix[0].size();
		int l = 0, r = col-1, u = 0, d = row-1;
		int curR = 0, curC = 0, curM = 0, nonRead = 1;
		ret.push_back(matrix[0][0]);
		while(r >= l || d >= u) {
			if (checkValid(curR+move[curM][0], curC+move[curM][1], l, r, u ,d)) {
				curR += move[curM][0];
				curC += move[curM][1];
				ret.push_back(matrix[curR][curC]);
			}
			else {
				l += move[curM][2];
				r += move[curM][3];
				u += move[curM][4];
				d += move[curM][5];
				curM = (curM + 1)%4;
			}
		}
		return ret;
	}
private:
	bool checkValid(int row, int col, int l, int r, int u, int d) {
		if (row < u || row > d)
			return false;
		if (col < l || col > r)
			return false;
		return true;
	}
};
int main() {
	int R, C;
	cin >> R >> C;
	vector<vector<int>> matrix(R, vector<int>(C, 0));
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> matrix[r][c];
	Solution sol;
	vector<int> ans = sol.spiralOrder(matrix);
	for (int i: ans)
		cout << i << " ";
	cout << endl;
	return 0;
}
