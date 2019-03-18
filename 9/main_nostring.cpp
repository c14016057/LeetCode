#include <iostream>
#include <string>
int p[10] = {0, 10, 100, 1000, 10000, 100000,1000000, 10000000, 100000000, 1000000000};
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		len = 0;
		for (int i = 9; i >= 0; i--)
			if (x >= p[i]) { 
				len = i+1;
				break;
			}
		while(len > 1) {
			len10 = p[len-1];
			if (x%10 != x/len10) 
				return false;
			x -= (x/len10)*len10;
			x /= 10;
			len -= 2;
		}
		return true;
	}
private:
	int len, len10;
};

int main() {
	int N;
	Solution Sol;
	cin >> N;
	cout << Sol.isPalindrome(N) << endl;
	return 0;
}
