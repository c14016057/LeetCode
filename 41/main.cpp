#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int num = nums.size();
		unordered_map<int, int> ht;
		for (int i = 0; i < num; i++) {
			ht[nums[i]]++;
		}
		for (int i = 1; i <=num+1; i++)
			if (ht.count(i) <= 0)
				return i;
		return 1;
	}
};
int main() {
	vector<int> nums;
	int N, n;
	cin >> N;
	while(N--) {
		cin >> n;
		nums.push_back(n);
	}
	Solution sol;
	cout << sol.firstMissingPositive(nums);
	return 0;
}
