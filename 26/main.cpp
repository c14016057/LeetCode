#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int l = 0;
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (i == size-1) 
				nums.at(l++) = nums.at(i);
			else if (nums.at(i)!=nums.at(i+1))
				nums.at(l++) = nums.at(i);	
		}
		return l;
	}
};

int main() {
	int N, num;
	vector<int> nums;
	Solution Sol;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	int l = Sol.removeDuplicates(nums);
	for (int i = 0; i < l; i++)
		cout << nums.at(i) << endl;
	return 0;
}
