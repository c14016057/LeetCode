#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
	int R = matrix.size();
	if (R == 0)
		return;
	int C = matrix[0].size(); 
	int row0 = 0, col0 = 0;
	for (int i = 0; i < R; i++)
		if (matrix[i][0] == 0)
			col0 = 1;
	for (int i = 0; i < C; i++)
		if (matrix[0][i] == 0)
			row0 = 1;
	for (int i = 1; i < R; i++)
		for (int j = 1; j < C; j++)
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;	
			}
	for (int i = 1; i < R; i++)
		for (int j = 1; j < C; j++)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
	if (row0 == 1)
		for (int i = 0; i < C; i++)
			matrix[0][i] = 0;
	if (col0 == 1)
		for (int i = 0; i < R; i++)
			matrix[i][0] = 0;
	return;
	}
};
int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> matrix[i][j];
	Solution sol;
	sol.setZeroes(matrix);
	for (vector<int> row: matrix) {
		for (int el :row)
			cout << el << " ";
		cout << endl;
	}
	return 0;
}
