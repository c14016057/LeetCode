#include <stdio.h>
#include <stdlib.h>
#define maxn 100000
#include "twoSum.c"
int input[maxn] = {};
int main() {
int n, t;
scanf("%d%d",&n, &t);
for (int i = 0; i < n; i++)
	scanf("%d",&input[i]);
int *res = twoSum(input, n, t);
printf("%d %d\n", res[0], res[1]);
free(res);
}
