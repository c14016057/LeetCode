#include <stdio.h>
#include <string.h>
#define maxl 10000
char S[maxl];
int mark[256] = {};
void setmark() {
	for (int i = 0; i < 256; i++)
		mark[i] = -1;
	return;
}
int lengthOfLongestSubstring(char* s) {
	setmark();
	int maxlen = 0, l = 0, len = strlen(s);
	for (int r = 0; r < len; r++) {
		if (mark[s[r]] >=l) {
			l = mark[s[r]] + 1;
			mark[s[r]] = r;
		}
		else {
			mark[s[r]] = r;
			maxlen = maxlen > r-l+1 ? maxlen : r-l+1;
		}
	}
	return maxlen;
}
int main() {
	scanf("%s", S);
	printf("%d\n", lengthOfLongestSubstring(S));
	return 0;
}
