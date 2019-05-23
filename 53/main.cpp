#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++)
			nums[i] = nums[i] + nums[i-1];
		int minPreSum = 0, maxsubSum = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			maxsubSum = max(maxsubSum, nums[i] - minPreSum);
			minPreSum = min(minPreSum, nums[i]);
		}
		return maxsubSum;			
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec(N, 0);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	Solution sol;
	cout << sol.maxSubArray(vec) << endl;
	return 0;
}
