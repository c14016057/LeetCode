#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return -1;
		int minpos = searchMin(nums, 0, len-1);
		int lpos = bs(nums, 0, minpos-1, target);
		int rpos = bs(nums, minpos, len-1, target);
		return (-1)*lpos*rpos;
		
	}
private:
	int searchMin(vector<int>& nums, int l, int r) {
		int k = (l+r)/2;
		if (nums[l] <= nums[r])
			return l;
		if (nums[k] < nums[r])
			return searchMin(nums, l, k);
		else return searchMin(nums, k+1, r);
	}
	int bs(vector<int>& nums, int l, int r, int target) {
		int k = (l+r)/2;
		if (l > r)
			return -1;
		if (nums[k] > target)
			return bs(nums, l, k-1, target);
		else if (nums[k] < target)
			return bs(nums, k+1, r, target);
		else
			return k ;
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
	cout << sol.search(vec, n);
	return 0;
}
