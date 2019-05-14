#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int r = nums.size()-1, l = 0;
		while(l <= r) {
			cout << l <<" "<< r << endl;
			if(nums[l] != val)
				l++;
			else if (nums[r] == val)
				r--;
			else {
				nums[l] = nums[r];
				l++;
				r--;
			}
		}
		return l;
	}
};
int main() {
	int N, val;
	cin >> N >> val;
	vector<int> vec;
	while(N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Solution sol;
	cout << sol.removeElement(vec, val) << endl;
	return 0;
}
