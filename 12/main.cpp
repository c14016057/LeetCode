#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
		string ret;
		//M
		int Thu = num/1000;
		while(Thu--)
			ret.append("M");
		num = num%1000;
		//Other
		for (int i = 0; i < 3; i++) {
			int N = num/div[i];
			if (N >= 5) {
				if (N == 9)
					ret.append(cor[i][2]+cor[i][0]);
				else {
					ret.append(cor[i][1]);
					while(N-- > 5)
						ret.append(cor[i][2]);
				}
			}
			else {
				if (N == 4)
					ret.append(cor[i][2]+cor[i][1]);
				else
					while(N--)
						ret.append(cor[i][2]);
			}
			num = num%div[i];
		}
		return ret;
	}
private:
	string cor[3][3] = {{"M","D","C"},{"C","L","X"},{"X","V","I"}};
	int div[3] = {100, 10, 1};
};
int main() {
	int num;
	cin >> num;
	Solution sol;
	cout << sol.intToRoman(num);
	return 0;
}
