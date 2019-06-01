#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> spiralOrder(int n) {
		int move[4][6] = {{ 0, 1, 0, 0, 1, 0}, 
						  { 1, 0, 0,-1, 0, 0}, 
						  { 0,-1, 0, 0, 0,-1}, 
						  {-1, 0, 1, 0, 0, 0}};//r c l r u d
		vector<vector<int>> ret(n, vector<int>(n));
		int l = 0, r = n-1, u = 0, d = n-1;
		int curR = 0, curC = 0, curM = 0, count = 2;
		ret[0][0] = 1;
		while(r >= l || d >= u) {
			if (checkValid(curR+move[curM][0], curC+move[curM][1], l, r, u ,d)) {
				curR += move[curM][0];
				curC += move[curM][1];
				ret[curR][curC] = count;
				count++;
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
	int n;
	cin >> n;
	Solution sol;
	vector<vector<int>> ans = sol.spiralOrder(n);
	for (vector<int> row: ans) {
		for (int enty: row)
			cout << enty << " ";
		cout << endl;
	}
	return 0;
}
