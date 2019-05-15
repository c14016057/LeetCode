#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		int max = nums[len-1];
		for (int i = len-1; i >=0; i--)
			if (nums[i] >= max) {
				max = nums[i];
				if (i == 0)
					std::sort(nums.begin(), nums.end());
			}
			else {
				int minsup = 2147483467;
				int minpos = -1;
				for (int j = i+1; j < len; j++)
					if (nums[j] > nums[i] && nums[j] < minsup) {
						minsup = nums[j];
						minpos = j;
					}
				int temp = nums[i];
				nums[i] = nums[minpos];
				nums[minpos] = temp;
				std::sort(nums.begin()+i+1, nums.end());
				break;	
			}
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
	sol.nextPermutation(vec);
	for(int i : vec) 
		cout << i << " ";
	cout << endl;
	return 0;
}
