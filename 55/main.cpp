#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
		int len = nums.size();
		int visit = 0;
		for (int i = 0; i < len; i++) {
			if (i > visit)
				return false;
			visit = max(visit, i+nums[i]);
		}
		return true;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	Solution sol;
	cout << sol.canJump(vec);
	return 0;
}
