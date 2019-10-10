#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		vector<vector<int>> ret;
		int min = 2147483647;
		for (int i = 0; i < arr.size()-1; i++)
			if (arr[i+1]-arr[i] < min) {
				min = arr[i+1]-arr[i];
				ret.clear();
				ret.push_back({arr[i], arr[i+1]});
			}
			else if (arr[i+1]-arr[i] == min)
				ret.push_back({arr[i], arr[i+1]});
		return ret;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> nums;
	while(N--) {
		int temp;
		cin >>temp;
		nums.push_back(temp);
	}
	Solution sol;
	vector<vector<int>> ans = sol.minimumAbsDifference(nums);
	for (vector<int> p: ans)
		cout << p[0] << " " << p[1] << endl;
		
	return 0;
}
