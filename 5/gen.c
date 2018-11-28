//Random generates a text file.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxl 10001
char buffer[maxl];
int main() {
	int l = 10000;
	srand(time(NULL));
	for (int i = 0; i < l ;i++)
		buffer[i] = rand()%26 + 'a';
	buffer[l] = 0;
	printf("%s", buffer);
}
