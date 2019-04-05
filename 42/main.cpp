#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
		int h;
		if (height.size() == 0)
			return 0;
		return dc(height, 0, height.size()-1, h);
	}
private:
	int dc(vector<int>& height, int l, int r, int& hpos) {
		if (r-l < 2) {
			hpos = height[r] > height[l] ? r : l;
			return 0;
		}
		//divide l-r to l-m and m+1-r
		int m = (r+l)/2, lhpos, rhpos;
		int ret = dc(height, l, m, lhpos) + dc(height, m+1, r, rhpos);
		int rainH;
		if (height[lhpos] > height[rhpos]) {
			rainH = height[rhpos];
			hpos = lhpos;
		}
		else {
			rainH = height[lhpos];
			hpos = rhpos;
		}
		for (int i = lhpos+1; i < rhpos; i++)
			if (height[i] < rainH) {
				ret+= (rainH - height[i]);
				height[i] = rainH;
			}
		return ret;
	}
};
int main() {
	vector<int> height;
	int N, h;
	cin >> N;
	while(N--) {
		cin >> h;
		height.push_back(h);
	}
	Solution sol;
	cout << sol.trap(height) << endl;
	for (int i = 0; i < height.size(); i++)
		cout << height[i] << " ";
	cout <<endl;
	return 0;
}
