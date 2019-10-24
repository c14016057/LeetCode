#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		return buy(0, prices, 0);	        
    }
	int buy(int idx, vector<int>& prices, int cur) {
		if (idx >= prices.size()-1)
			return cur;
		if (prices[idx] < prices[idx+1])
			return sell(idx+1, prices, cur-prices[idx]);
		else
			return buy(idx+1, prices, cur);
	}
	int sell(int idx, vector<int>& prices, int cur) {
		if (idx == prices.size()-1)
			return cur+prices[idx];
		if (prices[idx] > prices[idx+1])
			return buy(idx+1, prices, cur+prices[idx]);
		else
			return sell(idx+1, prices, cur);
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> stock;
	while(N--) {
		int temp;
		cin >> temp;
		stock.push_back(temp);
	}
	Solution sol;
	cout << sol.maxProfit(stock) << endl;
	return 0;
}
