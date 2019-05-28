#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int solveNQueens(int n) {
		vector<bool> col(n), Up(2*n-2), Down(2*n-2);
		return TryAll(n, 0, col, Up, Down);
	}
private:
	int TryAll(int n, int r, vector<bool>& col, vector<bool>& Up, 
		   vector<bool>& Down) {
		if (r == n) 
			return 1;
		int count = 0;
		for (int c = 0; c < n; c++) {
			int UpIdx = r+c;
			int DownIdx = r-c+n-1;
			if (col[c]||Up[UpIdx]||Down[DownIdx])
				continue;
			else {
				col[c] = true;
				Up[UpIdx] = true;
				Down[DownIdx] = true;
				count += TryAll(n, r+1, col, Up, Down);
				col[c] = false;
				Up[UpIdx] = false;
				Down[DownIdx] = false;
			}
		}
		return count;
	}
};
int main() {
	int N;
	cin >> N;
	Solution sol;
	cout << sol.solveNQueens(N) << endl;
	return 0;
}

