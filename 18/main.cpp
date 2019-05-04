#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int len = nums.size();
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		for (int i = 0; i < len; i++) {
			if (i > 0)
				if (nums[i]==nums[i-1])
					continue;
			for (int j = i+1; j < len; j++) {
				if (j > i+1)
					if (nums[j]==nums[j-1])
						continue;
				int sum = nums[i]+nums[j];
				int l = j+1, r = len -1;
				while(l < r) {
					if (sum+nums[l]+nums[r] < target)
						l++;
					else if(sum+nums[l]+nums[r] > target)
						r--;
					else {
						vector<int> ans = {nums[i], nums[j], nums[l], nums[r]};
						ret.push_back(ans);
						l++;
						while(l < len) {
							if (nums[l-1] == nums[l])
								l++;
							else
								break;
						}
					}
				}
			}
		}
		return ret;
	}
};
int main() {
	int N, target;
	vector<int> nums;
	cin >> N >> target;
	while(N--) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	Solution sol;
	vector<vector<int>> ans = sol.fourSum(nums, target);
	for (vector<int> p:ans) {
		for (int i:p) {
			cout << i << " ";
		}
		cout << endl;
	}
}
