#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#define maxn 100000
int array[maxn];
int main() {
	int n = 100000;
	int target = 300000;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		array[i] = i;
	array[n-1] = 300000;
	int shuffle = 30000;
	for (int i = 0; i < shuffle; i++) {
		int a = rand()%n, b = rand()%n, temp;
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
	printf("%d %d\n", n, target);
	for (int i = 0; i < n; i++)
		printf("%d%c", array[i], " \n"[i==n-1]);
}
