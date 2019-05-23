#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int l = matrix.size();
		//transpose
		for (int i = 0; i < l; i++)
			for (int j = i+1; j < l; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		//reflect
		for (int i = 0; i < l; i++)
			for (int j = 0; j < l/2; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][l-1-j];
				matrix[i][l-1-j] = temp;
			}
		return;
	}
};
int main() {
	int N;
	cin >> N;
	vector<vector<int>> matrix(N, vector<int>(N, 0));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
	for (vector<int> v: matrix) {
		for (int i: v)
			cout << i << " ";
		cout << endl;
	}
	Solution sol;
	sol.rotate(matrix);
	cout << "--------------" << endl;
	for (vector<int> v: matrix) {
		for (int i: v)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}
