#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
		std::sort(A.begin(), A.end());
		return countPermute(A, 0);
	}
private:
	int countPermute(vector<int>& A, int idx) {
		int ret = 0, len = A.size();
		if (idx == len) {
			for (int i : A)
				cout << i << " ";
			cout << std::endl;
			return 1;
		}
		for (int i = idx; i < len; i++) {
			if (i!= idx && A[idx] == A[i])
				continue;
			std::swap(A[idx], A[i]);
			if (idx == 0)
				ret += countPermute(A, idx+1);
			else if (checkSquare(0, A[idx-1]+A[idx], A[idx-1]+A[idx])) 
				ret += countPermute(A, idx+1);
			else {}
		}
		for (int i = idx; i < len-1; i++)
			std::swap(A[i], A[i+1]);
		return ret;
	}
	bool checkSquare(int l, int r, int target) {
		unsigned long long k = (l+r)/2;
		if (l > r)
			return false;
		if (k*k > target)
			return checkSquare(l, k-1, target);
		else if (k*k < target)
			return checkSquare(k+1, r, target);
		else 
			return true;
	}
};
int main() {
	int N;
	cin >> N;
	vector<int> vec;
	while(N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Solution sol;
	cout << sol.numSquarefulPerms(vec);
	return 0;
}
