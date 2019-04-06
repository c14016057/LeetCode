#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
		int ret = 0;
		//1000
		std::string::iterator f = s.begin(), r = s.end();
		while(f!=r) {
			if (*f != 'M')
				break;
			ret +=1000;
			f++;
		}
		//Other
		for (int i = 0; i < 3; i++) {
			if (f!=r) {
				if (f+1 != r) {
					if (*f == cor[i][2] && *(f+1) == cor[i][0]) {
						ret += div[i]-div[i+1];
						f += 2;
					}
					else if (*f == cor[i][2] && *(f+1) == cor[i][1]) {
						ret += div[i]/2-div[i+1];
						f += 2;
					}
					else {
						if (*f == cor[i][1]) {
							ret += div[i]/2;
							f++;
						}
						while(f!=r) {
							if (*f != cor[i][2])
								break;
							ret += div[i+1];
							f++;
						}
					}
				}
				else if (*f == cor[i][1]) {
					ret += div[i]/2;
					f++;
				}
				else if (*f == cor[i][2]) {
					ret += div[i+1];
					f++;
				}
			}
		}
	return ret;
	}
private:	
	char cor[3][3] = {{'M','D','C'},{'C','L','X'},{'X','V','I'}};
	int div[4] = {1000, 100, 10, 1};
};
int main() {
	string s;
	Solution sol;
	cin >> s;
	cout << sol.romanToInt(s);
	return 0;
}

