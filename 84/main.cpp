#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
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
		//for (int i : leftB)
		//	cout << i << " ";
		//cout << endl;
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
		//for (int i : rightB)
		//	cout << i << " ";
		//cout << endl;
		int m = (rightB[0] - leftB[0] - 1)*heights[0];
		for (int i = 1; i < nums; i++)
			m = max(m, (rightB[i] - leftB[i] - 1)*heights[i]);
		return m;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	Solution sol;
	cout << sol.lRectA(vec);

	return 0;
}
