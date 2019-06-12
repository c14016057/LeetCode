#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
		string ret;
		int lenA = a.size(), lenB = b.size();
		int carry = 0;
		int pta = lenA-1, ptb = lenB-1;
		while(pta >= 0 || ptb >= 0 || carry) {
			int inta, intb;
			if (pta < 0)
				inta = 0;
			else
				inta = a[pta]-'0';
			if (ptb < 0)
				intb = 0;
			else 
				intb = b[ptb]-'0';
			ret.append(std::to_string((inta+intb+carry)%2));
			carry = (inta+intb+carry)/2;
			pta--;
			ptb--;
		}
		int retlen = ret.size();
		for (int i = 0; i < retlen/2; i++)
			swap(ret[i], ret[retlen-1-i]);
		return ret;
	}
};
int main() {
	string a, b;
	cin >> a >> b;
	Solution sol;
	cout << sol.addBinary(a, b);
	return 0;
}
