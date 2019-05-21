#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
		string cur = "1";
		while(--n) {
			string next;
			int pos = 0, len = cur.size();
			while(pos < len) {
				int i = pos;
				for (; i < len; i++) 
					if (cur[i]!=cur[pos])
						break;
				next.append(std::to_string(i-pos));
				next.append(1,cur[pos]);
				pos = i;
			}
			cur = next;
		}
		return cur;
	}
};
int main() {
	int N;
	cin >> N;
	Solution sol;
	cout << sol.countAndSay(N) << endl;
	return 0;
}
