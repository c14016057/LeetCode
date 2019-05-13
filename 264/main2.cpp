#include <iostream>
#include <vector>
#include <cmath>
//r c v:2 3 5
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
		int flag[3] = {};//2, 3, 5 flag
		unsigned long long factor[3] = {2, 3, 5};
		unsigned long long dp[1690] = {};
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			for (int f = 0; f < 3; f++)
				while(dp[flag[f]]*factor[f] <= dp[i-1])
					flag[f]++;
			int min = 2147483647, minflag = -1;
			for (int f = 0; f < 3; f++)
				if (dp[flag[f]]*factor[f] < min) {
					min = dp[flag[f]]*factor[f];
					minflag = f;
				}
			dp[i] = min;
			flag[minflag]++;
		}
		return dp[n-1];
	}
};
int main() {
	
	int N;
	Solution sol;
	cin >> N;
	cout << sol.nthUglyNumber(N) << endl;;
	return 0;
}
