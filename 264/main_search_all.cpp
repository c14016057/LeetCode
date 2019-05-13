#include <iostream>
#include <vector>
#include <cmath>
#define MAXL 100
//r c v:2 3 5
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
		int count = 0, cur =1;
		while(1) {
			int tcur = cur;
			while(tcur%2 == 0)
				tcur/=2;
			while(tcur%3 == 0)
				tcur/=3;
			while(tcur%5 == 0)
				tcur/=5;
			if (tcur == 1)
				count++;
			if (count == n)
				return cur;
			cur++;
		}
	}
};
int main() {
	
	int N;
	Solution sol;
	cin >> N;
	cout << sol.nthUglyNumber(N) << endl;;
	return 0;
}
