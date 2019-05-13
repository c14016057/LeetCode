#include <iostream>
#include <vector>
#include <cmath>
#define MAXL 100
//r c v:2 3 5
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
		for (int i = 0; i < MAXL; i++)
			mcol[i] = 1;
		dp[0][0] = 1;
		mrow = 1;
		int count = 0, min = 1;
		while(count < n) {
			/*cout << "-----------------" << endl;
			for (int i  = 0; i < mrow; i++) {
				for (int j = 0; j < mcol[i]; j++)
					cout << dp[i][j] <<" ";
				cout << endl;
			}
			*/
			min = 2147483647;
			int maxc = -1, maxr = -1;
			for (int r = 0; r < mrow; r++)
				for (int c = 0; c < mcol[r]; c++)
					if (dp[r][c] < min) {
						min = dp[r][c];
						maxc = c;
						maxr =r;
					}
			if (maxr == mrow - 1) {
				dp[maxr+1][0] = (unsigned long long)pow(2, maxr+1);
				mrow++;
			}
			if (maxc == mcol[maxr]-1) {
				dp[maxr][maxc]*=5;
				dp[maxr][maxc+1] = (unsigned long long)pow(3, maxc+1)*(unsigned long long)pow(2, maxr);
				mcol[maxr]++;
			}
			else 
				dp[maxr][maxc]*=5;
			count++;
		}
		return min;

	}
private:
	unsigned long long dp[MAXL][MAXL];
	int mcol[MAXL];
	int mrow;
};
int main() {
	
	int N;
	Solution sol;
	cin >> N;
	cout << sol.nthUglyNumber(N) << endl;;
	return 0;
}
