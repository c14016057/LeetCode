#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size(), ret = nums[0]+nums[1]+nums[2];
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < len-2; i++) {
			int l = i+1, r = len-1;
			while(l < r) {
				int sum =nums[i] + nums[l] + nums[r];
				if (abs(ret-target) > abs(sum-target))
					ret = sum;
				if (sum > target)
					r--;
				else if (sum < target)
					l++;
				else 
					return sum;
			}
		}
		return ret;
	}
};
int main() {
	int N, n, target;
	cin >> N >> target;
	vector<int> nums;
	while(N--) {
		cin >> n;
		nums.push_back(n);
	}
	Solution sol;
	cout << sol.threeSumClosest(nums, target) << endl;
	return 0;
}
