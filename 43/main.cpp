#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
		int l = num2.size();
		string ret = "0";
		for (int i = l-1; i >= 0; i--) {
			string temp = mulByOne(num1, num2[i]-'0');
			if (temp != "0") {
				string zeros(l-i-1, '0');
				temp += zeros;
			}
			ret = sumString(ret, temp);
		}
		return ret;
	}
private:
	string mulByOne(string n1, int n2) {
		string ret = "0";
		while(n2--)
			ret = sumString(n1, ret);
		return ret;
	}
	string sumString(string n1, string n2) {
		vector<char> res;
		int l1 = n1.size(), l2 = n2.size(), l = max(l1, l2);
		int c = 0;
		for (int i = 0; i < l; i++) {
			int a = i < l1 ? n1[l1-i-1]-'0' : 0;
			int b = i < l2 ? n2[l2-i-1]-'0' : 0;
			res.push_back((a+b+c)%10+'0');
			c = (a+b+c)/10;
		}
		string ret;
		if (c!=0)
			ret.push_back(c+'0');
		for (int i = res.size()-1; i >=0; i--)
			ret.push_back(res[i]);
		return ret;
	}
};
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	Solution sol;
	cout << sol.multiply(s1, s2) << endl;
	return 0;
}
