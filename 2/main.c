#include <stdlib.h>
#include <stdio.h>
#define maxl 10000
typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;
ListNode L1[maxl] = {}, L2[maxl] = {};
void printlist(ListNode *a) {
	if (a == NULL) {
		printf("\n");
		return;
	}
	printf("%d", a->val);
	printlist(a->next);
	return;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	ListNode *first, *cur;
	first = malloc(sizeof(ListNode));
	int n1 = l1->val, n2 = l2->val, carry = 0;
	first->val = (n1+n2+carry)%10;
	carry = (n1+n2+carry)/10;
	l1 = l1->next;
	l2 = l2->next;
	cur = first;
	while(l1 != NULL || l2 != NULL || carry) {
		ListNode *new = malloc(sizeof(ListNode));
		if (l1 == NULL)
			n1 = 0;
		else {
			n1 = l1->val;
			l1 = l1->next;
		}
		if (l2 == NULL)
			n2 = 0;
		else {
			n2 = l2->val;
			l2 = l2->next;
		}
		new->val = (n1+n2+carry)%10;
		new->next = NULL;
		carry = (n1+n2+carry)/10;
		cur->next = new;
		cur = cur->next;
	}
	cur->next = NULL;
	return first;
}
int main() {
int n, m;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
	scanf("%d\n", &L1[i].val);
	if (i == n-1)
		L1[i].next = NULL;
	else
		L1[i].next = &L1[i+1];
}
printlist(&L1[0]);
scanf("%d", &m);
for (int i = 0; i < m; i++) {
	scanf("%d\n", &L2[i].val);
	if (i == m-1)
		L2[i].next = NULL;
	else
		L2[i].next = &L2[i+1];
}
printlist(&L2[0]);
struct ListNode *res = addTwoNumbers(&L1[0], &L2[0]);
printlist(res);
return 0;
}
