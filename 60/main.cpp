#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
		k--;
		vector<int> pow(n+1);
		vector<string> nums;
		string ans;
		pow[0] = 1;
		for (int i = 1; i < n+1; i++) {
			pow[i] = pow[i-1]*i;
			nums.push_back(std::to_string(i));
		}
		for (int i = n-1; i >=1; i--) {
			ans+=nums[k/pow[i]];
			nums.erase(nums.begin()+k/pow[i]);
			k = k%pow[i];
		}
		ans+=nums[0];
		return ans;

	}
};
int main() {
	int n, k;
	cin >> n >> k;
	Solution sol;
	cout << sol.getPermutation(n, k) << endl;

	return 0;
}
