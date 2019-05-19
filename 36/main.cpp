#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		int rowCheck[9][9] = {};
		int colCheck[9][9] = {};
		int blockCheck[9][9] = {};
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j]!='.') {
					//cout << "i j" << i << " " << j << endl;
					int r = i, c = j, br = i/3, bc = j/3, b = 3*br+bc;
					int num = board[i][j] - '0' - 1;
					//cout << r << " " << c << " " << b << " " << num << endl;
					if (rowCheck[r][num] == 1)
						return false;
					else
						rowCheck[r][num] = 1;

					if (colCheck[c][num] == 1)
						return false;
					else
						colCheck[c][num] = 1;

					if (blockCheck[b][num] == 1)
						return false;
					else
						blockCheck[b][num] = 1;
				}
		return true;
	}
};
int main() {
	vector<vector<char>> board;
	for(int i = 0; i < 9; i++) {
		vector<char> row;
		for(int j = 0; j < 9; j++) {
			char temp;
			cin >> temp;
			row.push_back(temp);
		}
		board.push_back(row);
	}
	for(vector<char> r : board) {
		for(char c : r)
			cout << c << " ";
		cout << endl;
	}
	Solution sol;
	cout << sol.isValidSudoku(board) << endl;
}
