#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(), nums.end(), cmp);
		int size = nums.size();
		int max1 = nums.at(size-1), max2 = nums.at(size-2);
		for (int i = 0; i < size-1; i++) {
			if (nums[i]+max1+max2 < 0)
				continue;
			if (nums[i] > 0)
				break;
			if (i!=0 &&	nums.at(i) == nums.at(i-1))
				continue;
			int bsr = size-1;
			for (int j = i+1; j < size-1; j++) {
				if (nums[i]+nums[j]+nums.at(bsr) < 0)
					continue;
				if (j >= bsr ) 
					break;
				if (j!=i+1 && nums.at(j) == nums.at(j-1))
					continue;
				int temp;
				if ((temp = bs(j+1, bsr, (-1)*(nums.at(i)+nums.at(j)), nums))>0) {
					bsr = temp;
					ret.push_back({nums.at(i), nums.at(j), (-1)*(nums.at(i)+nums.at(j))});
				}else {
					bsr = -1*temp;
				}
			}
		}
		return ret;
	}
private:
	static bool cmp(int i, int j) {return i<j;}
	int bsRight(int l, int r, int tar, vector<int>& nums) {
		int m = (l+r)/2;
		if (l>=r)
			return l;
		if (nums.at(m) == tar)
			return Right(m, r, tar, nums);
		if (nums.at(m) < tar)
			return bsRight(m+1, r, tar, nums);
		if (nums.at(m) > tar)
			return bsRight(l, m-1, tar, nums);
		return -1;
	}
	int Right(int m, int r, int tar, vector<int>& nums) {
		while(nums.at(m) == tar && m <nums.size())
			m++;
		return m;
	}
	int bsLeft(int l, int r, int tar, vector<int>& nums) {
		int m = (l+r)/2;	
		if (l>=r)
			return l;
		if (nums.at(m) == tar)
			return Left(m, l, tar, nums);
		if (nums.at(m) < tar)
			return bsLeft(m+1, r, tar, nums);
		if (nums.at(m) > tar)
			return bsLeft(l, m-1, tar, nums);
		return -1;
	}
	int Left(int m, int l, int tar, vector<int>& nums) {
		while(nums.at(m) == tar && m > 0 )
			m--;
		return m;
	}
	int bs(int l, int r, int tar, vector<int>& nums) {
		int m = (l+r)/2;
		if (l>r)
			return -1*l;
		if (nums.at(m) == tar)
			return m;
		else if (nums.at(m) > tar)
			return bs(l, m-1, tar, nums);
		else 
			return bs(m+1, r, tar, nums);
	}
	vector<vector<int>> ret;
};
int main() {
	int N;
	Solution Sol;
	cin >> N;
	vector<int> input(N);
	for (int i =0; i < N; i++) {
		int a;
		cin >> a;
		input.at(i) = a;
	}
	vector<vector<int>> ans = Sol.threeSum(input);
	for (int i =0; i < ans.size(); i++)
		cout <<ans.at(i).at(0)<<" "<<ans.at(i).at(1)<< " "<<ans.at(i).at(2)<<endl;
	return 0;
}
