#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int minS = prices[0], maxP = 0;
		for (int i = 0; i < prices.size(); i++) {
			minS = min(minS, prices[i]);
			maxP = max(maxP, prices[i] - minS);
		}
		return maxP;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec(N, 0);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	Solution sol;
	cout << sol.maxProfit(vec) << endl;
	
	return 0;
}
