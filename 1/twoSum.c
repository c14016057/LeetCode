#include <stdlib.h>

#ifndef NLOGNOPT
int* twoSum(int* nums, int numsSize, int target) {
	int *res = malloc(2*sizeof(int));
	for (int i = 0; i < numsSize; i++)
		for (int j = i+1; j < numsSize; j++)
			if (nums[i] + nums[j] == target) {
				res[0] = i;
				res[1] = j;
				return res;
			}
	return NULL;
}
#endif

#ifdef NLOGNOPT
typedef struct pack {
	int num;
	int idx;
} pack;
int cmp (const void *s1, const void *s2) {
	return ((pack*)s1)->num > ((pack*)s2)->num;
}
int binSearch(pack* ary, int l, int r, int target) {
	if (l>r) return -1;
	int m = (l+r)/2;
	if (ary[m].num == target)
		return ary[m].idx;
	if (ary[m].num > target)
		return binSearch(ary, l, m-1, target);
	if (ary[m].num < target)
		return binSearch(ary, m+1, r, target);
	return -1;
}
int* twoSum(int* nums, int numsSize, int target) {
	int *res = malloc(2*sizeof(int));
	pack ary[numsSize];//max size??
	for (int i = 0; i < numsSize; i++) {
		ary[i].num = nums[i];
		ary[i].idx = i;
	}
	qsort(ary, numsSize, sizeof(pack), cmp);
	for (int i = 0; i < numsSize; i++){
		int find = binSearch(ary, i+1, numsSize-1, target-ary[i].num);
		if (find != -1) {
			res[0] = find > ary[i].idx ? ary[i].idx:find;
			res[1] = find < ary[i].idx ? ary[i].idx:find;
			return res;
		}		
	}
	return NULL;
}
#endif
