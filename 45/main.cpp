#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size(), curFar = 0;
		vector<int> bfs(len);
		bfs[0] = 0;
		for (int i = 0; i <	len-1; i++) {
			for (int j  = curFar+1; j <= i+nums[i]; j++)
				if (j < len)
					bfs[j] = bfs[i] + 1;
			curFar = curFar > i+nums[i] ? curFar : i+nums[i];
		}
		return bfs[len-1];

	}
};
int main() {
	int N, n;
	vector<int> nums;
	cin >> N;
	while(N--) {
		cin >> n;
		nums.push_back(n);
	}
	Solution sol;
	cout << sol.jump(nums);
	return 0;
}
