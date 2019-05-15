#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
        if (nums.size()==0) {
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		ret.push_back(bs(nums, 0, nums.size()-1, target-0.1));
		ret.push_back(bs(nums, 0, nums.size()-1, target+0.1));
		return ret;
	}
private:
	int bs(vector<int>& nums, int l, int r, double target) {
		int k = (l+r)/2;
		if (l == r)
			if (abs(target-nums[l]) < 0.11)
				return l;
			else return -1;
		if (r-l==1)  {
			if (abs(target-nums[l]) < 0.11 && target < nums[r])
				return l;
			else if (abs(target-nums[r]) < 0.11) 
				return r;
			return -1;
		}
		if (nums[k] > target)
			return bs(nums, l, k, target);
		else
			return bs(nums, k ,r, target);
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
	vector<int> res = sol.searchRange(vec, n);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}
