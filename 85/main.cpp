#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxRect(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0)
			return 0;
		int col = matrix[0].size();
		vector<vector<int>> dp(row+1, vector<int>(col));
		for (int i = 1; i < row+1; i++)
			for (int j = 0; j < col; j++)
				if (matrix[i-1][j] == '0')
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i-1][j]+1;

		/*for (vector<int> row: dp) {
			for (int el: row) 
				cout << el << " ";
			cout << endl;
		}*/
			
		int Max = -1;
		for (int i = 1; i < row+1; i++)
			Max = max(Max, lRectA(dp[i]));
		return Max;

	}
    int lRectA(vector<int>& heights) {
		int nums = heights.size();
		if (nums == 0)
			return 0;
		vector<int> leftB(nums);
		vector<int> rightB(nums);
		vector<int> stack;
		for (int i = 0; i < nums; i++) {
			while(!stack.empty()) {
				if (heights[stack[stack.size()-1]] >= heights[i])
					stack.pop_back();
				else
					break;
			}
			if (stack.empty())
				leftB[i]= -1;
			else
				leftB[i] = stack[stack.size()-1];
			if (i < nums-1) {//find possible left bound
				if (heights[i] < heights[i+1])
					stack.push_back(i);
			}
		}
		stack.clear();
		for (int i = nums-1; i >=0; i--) {
			while(!stack.empty()) {
				if (heights[stack[stack.size()-1]] >= heights[i])
					stack.pop_back();
				else
					break;
			}
			if (stack.empty())
				rightB[i]= nums;
			else
				rightB[i] = stack[stack.size()-1];
			if (i > 0) {//find possible right bound
				if (heights[i] < heights[i-1])
					stack.push_back(i);
			}
		}
		int m = (rightB[0] - leftB[0] - 1)*heights[0];
		for (int i = 1; i < nums; i++)
			m = max(m, (rightB[i] - leftB[i] - 1)*heights[i]);
		return m;
	}
};
int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<char>> vec(r, vector<char>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			int temp;
			cin >> temp;
			vec[i][j] = '0'+temp;
		}
	Solution sol;
	cout << sol.maxRect(vec);
	return 0;
}
