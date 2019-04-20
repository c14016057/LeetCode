#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int N = 10000;
	srand(time(NULL));
	printf("%d\n", N);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", rand()%N, rand()%N);
}
