#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
	int N;
	char c;
	scanf("%d", &N);
	printf("%d\n", N);
	scanf("%c", &c);
	while(scanf("%d", &N)!=EOF) {
		scanf("%c", &c);
		printf("%d\n", N);
	}
	return 0;
}
