#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        if (len == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int pos = bs(intervals, 0, len-1, newInterval[0]);
		if (pos == 0) {
			if (newInterval[1] < intervals[0][0])
				intervals.insert(intervals.begin(), newInterval);
			else {
				int i = bs_r(intervals, pos, len-1, newInterval[1]);
				cout << i << endl;
				intervals[0][0] = newInterval[0];
				if (i > pos) {
					intervals[0][1] = max(newInterval[1], intervals[i-1][1]);
					intervals.erase (intervals.begin()+1, intervals.begin()+i);
				}
			}
		}
		else if (pos == len) {
			if (intervals[len-1][1] < newInterval[0])
				intervals.push_back(newInterval);
			else
				intervals[len-1][1] = max(intervals[len-1][1], newInterval[1]);
		}
		else {
			if (newInterval[0] <= intervals[pos-1][1]) {
				intervals[pos-1][1] = max(intervals[pos-1][1], newInterval[1]);
				int i = bs_r(intervals, pos-1, len-1, intervals[pos-1][1]);
				if (i > pos-1) {
					intervals[pos-1][1] = max(intervals[pos-1][1], intervals[i-1][1]);
					intervals.erase(intervals.begin()+pos, intervals.begin()+i);
				}
			}
			else if (newInterval[1] >= intervals[pos][0]) {
				intervals[pos][0] = newInterval[0];
				int i = bs_r(intervals, pos, len-1, newInterval[1]);
				if (i > pos) {
					intervals[pos][1] = max(newInterval[1], intervals[i-1][1]);
					intervals.erase(intervals.begin()+pos+1, intervals.begin()+i);
				}
			}
			else
				intervals.insert(intervals.begin()+pos, newInterval);
		}
        return intervals;         
    }
private:
    int bs(vector<vector<int>>& intervals, int l, int r, int target) {
        if (r-l <= 1) {
            if (target > intervals[r][0])
                return r+1;
            else if (target <= intervals[l][0])
                return l;
            else return l+1;
        }
        int m = (l+r)/2;
        if (intervals[m][0] < target)
            return bs(intervals, m, r, target);
        else if (intervals[m][0] > target)
            return bs(intervals, l, m, target);
        else return m;
    }
    int bs_r(vector<vector<int>>& intervals, int l, int r, int target) {
        if (r-l <= 1) {
            if (target >= intervals[r][0])
                return r+1;
            else if (target >= intervals[l][0])
                return r;
            else return l;
        }
        int m = (l+r)/2;
        if (intervals[m][0] < target)
            return bs_r(intervals, m, r, target);
        else if (intervals[m][0] > target)
            return bs_r(intervals, l, m, target);
        else return m+1;
    }
};
int main() {
	int N, x, y;
	vector<vector<int>> intervals;
	cin >> N;
	while(N--) {
		cin >> x >> y;
		vector<int> temp = {x, y};
		intervals.push_back(temp);
	}
	cin >> x >> y;
	vector<int> newIntervals = {x, y};	
	Solution sol;
	vector<vector<int>> out = sol.insert(intervals, newIntervals);
	//print result
	for (int i = 0; i < out.size(); i++)
		cout <<'['<<out[i][0]<<", "<<out[i][1]<<"] ";
	cout << endl;
	return 0;
}
