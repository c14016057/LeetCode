#include <stdio.h>
#include "maxPoints.h"
typedef struct Point Point;
Point points[maxN];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &points[i].x, &points[i].y);
	printf("%d\n", maxPoints(points, N));
	return 0;
}
