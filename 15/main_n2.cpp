//n^2 sol
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(), nums.end(), cmp);
		int size = nums.size();
		int max1 = nums.at(size-1), max2 = nums.at(size-2);
		for (int i = 0; i < size-1; i++) {
			if (nums[i]+max1+max2 < 0)
				continue;
			if (nums[i] > 0)
				break;
			if (i!=0 &&	nums.at(i) == nums.at(i-1))
				continue;
			int j = i+1, k = size-1;
			while(j < k) {
				if (nums.at(i)+nums.at(j)+nums.at(k) == 0) {
					ret.push_back({nums.at(i), nums.at(j), nums.at(k)});
					int next = j+1;
					while(nums.at(next) == nums.at(j)) {
						next++;
						if (next > k)
							break;
					}
					j = next;
					
				}
				else if (nums.at(i)+nums.at(j)+nums.at(k) < 0)
					j++;
				else
					k--;
			}
		}
		return ret;
	}
private:
	static bool cmp(int i, int j) {return i<j;}
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
	for (int i =0; i < ans.size(); i++)
		cout <<ans.at(i).at(0)<<" "<<ans.at(i).at(1)<< " "<<ans.at(i).at(2)<<endl;
	return 0;
}
