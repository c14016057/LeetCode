#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxl 10001
//O(n^3)
/*
char* longestPalindrome(char* s) {
	char *res = malloc(sizeof(char)*maxl);
	int len = strlen(s);
	if (len == 0) return "";
	for (int L = len; L > 0; L--){
		for (int rg = 0; rg <= len - L; rg++) {
			int valid = 1;
			for (int l = 0; l < (L+L%2)/2; l++)
				if (s[rg+l] != s[rg+L-1-l]) {
					valid = 0;
					break;
				}
			if (valid) {
				for (int l = 0; l < L; l++)
					res[l] = s[rg+l];
				res[L] = 0;
				return res;
			}
		}
	}
	return NULL;
}
*/

//dp O(n^2)solution
/*
int dp[maxl][maxl] = {};//L , l
char* longestPalindrome(char* s) {
	int len = strlen(s);
	int maxlen = 1;
	if (len == 0) return "";
	for (int l = 0; l < len; l++)
		dp[1][l] = 1;
	for (int l = 0; l < len -1; l++)
		if (s[l] == s[l+1]) {
			dp[2][l] = 2;
			maxlen = 2;
		}
		else
			dp[2][l] = 0;
	int fail = 0;
	for (int L = 3; L <= len; L++) {
		int count = 0;
		for (int l = 0; l <= len - L; l++) {
			if (s[l] == s[l+L-1] && dp[L-2][l+1]) {
				dp[L][l] = L;
				maxlen = L;
				count = 1;
			}
			else
				dp[L][l] = 0;
		}
		if (count == 0) fail++;
		else fail = 0;
		if (fail == 2 ) 
			break;
	}
	for (int l = 0; l <= len-maxlen; l++)
		if (dp[maxlen][l] == maxlen) {
			char *res = malloc(sizeof(char)*maxl);
			for (int k = 0; k < maxlen; k++)
				res[k] = s[k+l];
			res[maxlen] = 0;
			return res;
 		}
	return NULL;
}
*/

//O(n) solution
int z[2*maxl-1] = {}, zi[2*maxl-1] = {};
char output[maxl] = {};
void printzi(int *tar, int l) {
	for (int i = 0; i < l; i++)
		printf("%d%c", zi[i], " \n"[i==l-1]);
	return;
}
int extend(int cent, int l, int search_st) {
	int search_rg = l - cent - 1 > cent ? cent : l - cent - 1;
	for (int i = search_st; i <= search_rg; i++)
		if (z[cent + i] != z[cent - i])
			return i-1;
	return search_rg;
}
char* longestPalindrome(char* s) {
	int len = strlen(s);
	for (int i = 0; i < 2*len-1; i++)
		if (i%2 == 0)
			z[i] = (int)s[i/2];
		else
			z[i] = -1;
	len = 2*len-1;
	//compute zi
	int r = 0, rcent = 0, maxzi = 0, maxz = 0;
	for (int i = 1; i < len; i++)
		if (i > r) {
			zi[i] = extend(i, len, 0);
			if (zi[i] > maxzi) {
				maxzi = zi[i];
				maxz = i;
			}
			else if (zi[i] == maxzi && z[i+zi[i]]>0) {
				maxzi = zi[i];
				maxz = i;
			}
			rcent = i;
			r = rcent + zi[rcent];
		}
		else {
			int miri = 2*rcent-i;
			if (i+zi[miri] < r)
				zi[i] = zi[miri];
			else if (i+zi[miri] == r) {
				zi[i] = extend(i, len, r - i + 1);
				if (zi[i] > maxzi) {
					maxzi = zi[i];
					maxz = i;
					rcent = i;
					r = rcent + zi[rcent];
				}
				else if (zi[i] == maxzi && z[i+zi[i]]>0) {
					maxzi = zi[i];
					maxz = i;
				}
				if (i+zi[i] > r) {
					r = i + zi[i];
					rcent = i;
				}
			}
			else 
				zi[i] = r - i;
		}
//	printzi(zi, len);
//	printf("%d %d\n", maxz, maxzi);
	int len_count = 0;
	for (int i = maxz-maxzi; i <= maxz+maxzi && i < len; i++)
		if (z[i] > 0) 
			output[len_count++] = (char) z[i];
	output[len_count] = 0;
	return output;
}
char s[maxl] = {};
int main() {
	scanf("%s", s);
	printf("%s\n", longestPalindrome(s));
	return 0;
}
