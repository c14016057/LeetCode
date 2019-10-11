#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.size();
		vector<int> disj(len);
		for (int i = 0; i < len; i++)
			disj[i] = i;
		for (vector<int> p: pairs)
			_union(p[0], p[1], disj);
		for (int i = 0; i < len; i++)
			_find(i, disj);
		vector<vector<int>> countsort(len, vector<int>(26, 0));
		for (int i = 0; i < len ;i++)
			countsort[disj[i]][s[i]-'a']++;
		vector<int> pt(len, 0);//pointer to the next non zero char of each set
		string ret(len, 0);
		for (int i = 0; i < len; i++) {
			int ts = disj[i];//target set
			while(countsort[ts][pt[ts]]==0)
				pt[ts]++;
			ret[i] = ((char)pt[ts] + 'a');
			countsort[ts][pt[ts]]--;
		}
		return ret;

    }
	int _find(int n, vector<int>& disj) {
		if (disj[n] != n)
			disj[n] = _find(disj[n], disj);
		return disj[n];
	}
	void _union(int a, int b, vector<int>& disj) {
		int ap = _find(a, disj), bp = _find(b, disj);
		disj[ap] = bp;
		return;
	}

};
int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<vector<int>> pairs;
	while(n--) {
		int a, b;
		cin >> a >> b;
		pairs.push_back({a, b});
	}
	Solution sol;
	cout << sol.smallestStringWithSwaps(s, pairs);
	return 0;
}
