#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		if (nums.size()==0)
			return 0;
		return bs(nums, 0, nums.size()-1, target);
	}
private:
	int bs(vector<int>& nums, int l, int r, int target) {
		int k = (l+r)/2;
		if (l == r) {
			if (nums[l] >= target)
				return l;
			else 
				return l+1;
		}
		if (nums[k] < target)
			return bs(nums, k+1, r, target);
		else if (nums[k] > target)
			return bs(nums, l, k, target);
		else return k;
	}
};
int main() {
	int N, n;
	cin >> N >> n;
	vector<int> vec;
	while(N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Solution sol;
	cout << sol.searchInsert(vec, n) << endl;
	return 0;
}
