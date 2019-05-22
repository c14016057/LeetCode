#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> ret;
		vector<int> ans;
		pick(ret, candidates, ans, 0, target, 1);
		return ret;
	}
private:
	void pick(vector<vector<int>>& ret, vector<int>& candi, vector<int>& ans, 
			int idx, int target, int befPick) {
		if (target == 0) {
			ret.push_back(ans);
			return ;
		}
		if (idx == candi.size())
			return;
		if (candi[idx] > target)
			return;
		if (befPick == 0) {
			if (candi[idx] == candi[idx-1])
				pick(ret, candi, ans, idx+1, target, 0);
			else {
				ans.push_back(candi[idx]);
				pick(ret, candi, ans, idx+1, target - candi[idx], 1);
				ans.pop_back();
				pick(ret, candi, ans, idx+1, target, 0);
			}
		}
		else {	
			ans.push_back(candi[idx]);
			pick(ret, candi, ans, idx+1, target - candi[idx], 1);
			ans.pop_back();
			pick(ret, candi, ans, idx+1, target, 0);
		}
		return;
		
	}
};
int main() {
	int N, n;
	cin >> N >> n;
	vector<int> vec;
	while (N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Solution sol;
	vector<vector<int>> ans = sol.combinationSum2(vec, n);
	for (vector<int> v: ans) {
		for (int i: v)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
