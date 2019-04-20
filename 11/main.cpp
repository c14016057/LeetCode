#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
		int size = height.size(), max = 0;
		for (int i = 0; i < size; i++)
			for (int j = i+1; j <size; j++)
				max = max > (j-i)*min(height[i], height[j]) ? max : (j-i)*min(height[i], height[j]);
		return max;
	}
private:
	static int min(int i, int j) {
		if (i < j) return i;
		return j;
	}
};
int main() {
	int N, num;
	vector<int> nums;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	Solution Sol;
	cout << Sol.maxArea(nums) << endl;
	return 0;
}
