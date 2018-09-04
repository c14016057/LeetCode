#include <stdio.h>
#define maxl 10000
int a[maxl], b[maxl];
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size, l1 = 0, l2 = 0;
	int nums3[len];//stack?
	for (int i = 0; i < len; i++) {
		if (l2 == nums2Size) {
			nums3[i] = nums1[l1];
			l1++;
		}
		else if (l1 == nums1Size) {
			nums3[i] = nums2[l2];
			l2++;
		}
		else if (nums1[l1] < nums2[l2]) {
			nums3[i] = nums1[l1];
			l1++;
		}
		else {
			nums3[i] = nums2[l2];
			l2++;
		}
	}
	if (len%2 == 0)
		return ((double)(nums3[len/2] + nums3[len/2-1]))/2.0;
	else
		return (double)nums3[len/2];
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	printf("%lf\n", findMedianSortedArrays(a, n, b, m));
return 0;
}
