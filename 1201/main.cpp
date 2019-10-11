#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n, int aa, int bb, int cc) {
		long long a = aa, b = bb, c = cc;
		long long ab = a*b/gcd(a, b), 
				  ac = a*c/gcd(a, c), 
				  bc = b*c/gcd(b, c);
		long long ab_c_gcd = gcd(ab, c);
		long long abc = ab*c/ab_c_gcd;
		vector<long long> lcm = {a, b, c, ab, ac, bc, abc};
		//for (auto num: lcm)
		//	cout << num << endl;
		return bs(1, 2000000000, n, lcm);
	}
	int bs(long long l, long long r, int n, vector<long long> &lcm) {
		long long target = (l+r)/2;
		long long count = target/lcm[0] + target/lcm[1] + target/lcm[2]
		   			-target/lcm[3] - target/lcm[4] - target/lcm[5]
					+target/lcm[6];
		if (count == n) {
			if (target%lcm[0]==0 || target%lcm[1]==0 || target%lcm[2]==0)
				return target;
			return bs(l, target-1, n, lcm);
		}
		else if (count < n)
			return bs(target+1, r, n, lcm);
		else 
			return bs(l, target-1, n, lcm);
	}
	int gcd(int n1, int n2) {
		if (n2 == 0)
			return n1;
		return gcd(n2, n1%n2);
	}
};
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	Solution sol;
	cout << sol.nthUglyNumber(n, a, b, c) << endl;
	return 0;
}
