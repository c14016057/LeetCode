#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		std::sort(intervals.begin(), intervals.end(), cmp);
		vector<vector<int>> ret;
		int n = intervals.size();
		if (n == 0)
			return ret;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (intervals[i][0] <= intervals[cur][1])
				intervals[cur][1] = max(intervals[cur][1], intervals[i][1]);
			else {
				ret.push_back(intervals[cur]);
				cur = i;
			}
		}
		ret.push_back(intervals[cur]);
		return ret;
	}
};
int main() {
	int N;
	cin >> N;
	vector<vector<int>> intervals(N, vector<int>(2));
	for (int i = 0; i < N; i++)
		cin >> intervals[i][0] >> intervals[i][1];
	Solution sol;
	vector<vector<int>> newIntervals = sol.merge(intervals);
	for (vector<int> pair: newIntervals) 
		cout <<"["<<pair[0] <<", "<<pair[1]<<"] ";
	cout << endl;
	return 0;
}
