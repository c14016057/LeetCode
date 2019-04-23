#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int len = intervals.size();
        if (len == 0) {
            ret.push_back(newInterval);
            return ret;
        }
        int i = 0;
        for (; i < len; i++)
            if (newInterval[0] > intervals[i][1])
                ret.push_back(intervals[i]);
            else if (newInterval[1] < intervals[i][0]) {
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                break;
            }
            else {
                vector<int> temp(2, 0);
                temp[0] = min(intervals[i][0], newInterval[0]);
                temp[1] = max(intervals[i][1], newInterval[1]);
                ret.push_back(temp);
                break;
            }
        if (i == len)
            ret.push_back(newInterval);
        int j = i+1;
        for (; j < len; j++)
            if (intervals[j][0] <= ret[i][1])
                ret[i][1] = max(ret[i][1], intervals[j][1]);
            else
                break;
        for (; j < len; j++)
            ret.push_back(intervals[j]);
        return ret;
        
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
