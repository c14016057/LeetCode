#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		perm(nums, ret, 0);
		return ret;
	}
private:
	void perm(vector<int>& nums, vector<vector<int>>& ret, int idx) {
		if (idx == nums.size()-1) {
			ret.push_back(nums);
			return;
		}
		for (int i = idx; i < nums.size(); i++) {
			int temp = nums[idx];
			nums[idx] = nums[i];
			nums[i] = temp;
			perm(nums, ret, idx+1);
		}
		for (int i = idx; i < nums.size()-1; i++) {
			int temp = nums[i];
			nums[i] = nums[i+1];
			nums[i+1] = temp;
		}
		return;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec;
	while(N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Solution sol;
	vector<vector<int>> res = sol.permute(vec);
	for (vector<int> a:res) {
		for (int n : a)
			cout << n << " ";
		cout << endl;
	}
	return 0;
}
