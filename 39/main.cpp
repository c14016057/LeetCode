#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		vector<int> ans;
		std::sort(candidates.begin(), candidates.end());
		pick(ret, candidates, ans, 0, target);
		return ret;
	}
private:
	void pick(vector<vector<int>>& ret, vector<int>& candi, 
			vector<int> ans, int idx, long long target) {
		if (target == 0) {
			ret.push_back(ans);
			return;
		}
		if (idx == candi.size())
			return;
		long long picktimes = 0;
		while(target - picktimes*candi[idx] >= 0) {
			if (picktimes)
				ans.push_back(candi[idx]);
			pick(ret, candi, ans, idx+1, target-picktimes*candi[idx]);
			picktimes++;
		}
		return;
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
	vector<vector<int>> res = sol.combinationSum(vec, n);
	for (vector<int> v : res) {
		for (int i :v)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
