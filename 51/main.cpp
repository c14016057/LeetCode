#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		 vector<string> ans;
		 vector<vector<string>> ret;
		 vector<bool> col(n), Up(2*n-2), Down(2*n-2);
		 TryAll(n, 0, col, Up, Down, ans, ret);
		 return ret;
	}
private:
	void TryAll(int n, int r, vector<bool>& col, vector<bool>& Up, 
		   vector<bool>& Down, vector<string>& ans, vector<vector<string>>& ret) {
		if (r == n) {
			ret.push_back(ans);
			return;
		}
		for (int c = 0; c < n; c++) {
			int UpIdx = r+c;
			int DownIdx = r-c+n-1;
			if (col[c]||Up[UpIdx]||Down[DownIdx])
				continue;
			else {
				col[c] = true;
				Up[UpIdx] = true;
				Down[DownIdx] = true;
				ans.push_back(string(c,'.')+"Q"+string(n-c-1, '.'));
				TryAll(n, r+1, col, Up, Down, ans, ret);
				col[c] = false;
				Up[UpIdx] = false;
				Down[DownIdx] = false;
				ans.pop_back();
			}
		}
		return;	
	}
};
int main() {
	int N;
	cin >> N;
	Solution sol;
	vector<vector<string>> ans = sol.solveNQueens(N);
	for(vector<string> board: ans) {
		cout << "------------" << endl;
		for (string row: board)
			cout << row << endl;
	}
	return 0;
}

