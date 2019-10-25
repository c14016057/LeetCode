#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
		vector<int> maxleft(N+1, 0);
		vector<int> maxright(N, 0);
		int curmin = prices[0];
		int curmax = prices[N-1];
		for (int i = 1; i < N; i++) {
			maxleft[i+1] = max(maxleft[i+1], prices[i] - curmin);
			curmin = min(curmin, prices[i]);
		}
		for (int i = N-2; i >= 0; i--) {
			maxright[i] = max(maxright[i], curmax - prices[i]);
			curmax = max(curmax, prices[i]);
		}
		int ret = 0;
		for (int i = 1; i < N+1; i++)
			maxleft[i] = max(maxleft[i], maxleft[i-1]);
		for (int i = N-2; i >=0; i--)
			maxright[i] = max(maxright[i+1], maxright[i]);
		for (int i =0; i < N; i++)
			ret = max(ret, maxright[i]+maxleft[i]);
		return ret;
		/*
		for (vector<int> vec: table) {
			for (int num: vec)
				cout << num << "  ";
			cout << endl;
		}
		*/
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
