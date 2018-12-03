#include <stdio.h>
#include "convert.h"
#define maxL 100
char S[maxL] = {};
int main() {
	int numRaws;
	scanf("%d%s",&numRaws, S);
	printf("%s\n", convert(S, numRaws));
	return 0;
}
