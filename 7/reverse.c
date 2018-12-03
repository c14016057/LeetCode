#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
int reverse(int x) {
	char num[20] = {'+'};
	if (x < 0) {
		num[0] = '-';
		x *= -1;
	}
	sprintf(&num[1], "%d", x);
	int len = strlen(num);
	for (int i = 1; i < (len+1)/2; i++) {
		char temp = num[i];
		num[i] = num[len-i];
		num[len-i] = temp;
	}
	long long revnum = atoll(num);
	if (revnum > INT_MAX || revnum < INT_MIN)
		return 0;
	return (int)revnum;
}
