#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
		vector<vector<int>> rowCheck(9, vector<int>(9, 0));
		vector<vector<int>> colCheck(9, vector<int>(9, 0));
		vector<vector<int>> bolCheck(9, vector<int>(9, 0));
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j]!='.') {
					int r = i, c = j, br = r/3, bc = c/3, b = 3*br+bc;
					int num = board[i][j] - '1';
					rowCheck[r][num] = 1;
					colCheck[c][num] = 1;
					bolCheck[b][num] = 1;
				}
		fill(board, 0, rowCheck, colCheck, bolCheck);
		return;
	}
private:
	bool fill(vector<vector<char>>& board, int idx, vector<vector<int>>& rowCheck, 
			vector<vector<int>>& colCheck, vector<vector<int>>& bolCheck) {
		if (idx == 81)
			return true;
		int r = idx/9, c = idx%9, br = r/3, bc = c/3, b = 3*br+bc;
		if (board[r][c] == '.') {
			for (int num = 0; num < 9; num++)
				if (!(rowCheck[r][num] || colCheck[c][num] || bolCheck[b][num])) {
					board[r][c] = num+ '1';
					rowCheck[r][num] = 1;
					colCheck[c][num] = 1;
					bolCheck[b][num] = 1;
					if(fill(board, idx+1, rowCheck, colCheck, bolCheck))
						return true;
					board[r][c] = '.';
					rowCheck[r][num] = 0;
					colCheck[c][num] = 0;
					bolCheck[b][num] = 0;
				}
			return false;
		}
		else
			return fill(board, idx+1, rowCheck, colCheck, bolCheck);
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
	sol.solveSudoku(board);
	for(vector<char> r : board) {
		for(char c : r)
			cout << c << " ";
		cout << endl;
	}

}
