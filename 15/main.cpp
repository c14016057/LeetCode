#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	static bool cmp(int i, int j) {return i<j;}
	vector<vector<int>> threeSum(vector<int>& nums) {
		ret.clear();
		if (nums.empty())
			return ret;
		sort(nums.begin(), nums.end(), cmp);
		int min = nums.front(), max = nums.back();
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]+2*max < 0)
				continue;
			if (nums[i] > 0)
				break;
			if (i!=0 &&	nums.at(i) == nums.at(i-1))
				continue;
			for (int j = i+1; j < nums.size(); j++) {
				if (nums[i]+nums[j]+max < 0)
					continue;
				if (nums[i]+nums[j] > 0)
					break;
				if (j!=i+1 && nums.at(j) == nums.at(j-1))
					continue;
				for (int k = j+1; k < nums.size(); k++) 
					if (nums.at(i)+nums.at(j)+nums.at(k) == 0) {
						newans(nums.at(i), nums.at(j), nums.at(k));
						break;
					}
			}
		}
		return ret;
	}
	void newans(int i, int j, int k) {
		vector<int> ans;
		ans.push_back(i);
		ans.push_back(j);
		ans.push_back(k);
		ret.push_back(ans);
	}
	vector<vector<int>> ret;
};
int main() {
	int N;
	Solution Sol;
	cin >> N;
	vector<int> input(N);
	for (int i =0; i < N; i++) {
		int a;
		cin >> a;
		input.at(i) = a;
	}
	vector<vector<int>> ans = Sol.threeSum(input);
//	for (int i =0; i < ans.size(); i++)
//		cout <<ans.at(i).at(0)<<" "<<ans.at(i).at(1)<< " "<<ans.at(i).at(2)<<endl;
	return 0;
}
