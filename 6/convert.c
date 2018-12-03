#include <string.h>
#include <stdio.h>
#define maxL 10000
#define maxR 10000
char conS[maxL] = {};
int rowStart[maxR] = {};//the i'th row of converted string starts on index rowStart[i] of conS[]
int rowCount[maxR] = {};//count put char in conS for each row
char* convert(char* s, int numRows) {
	int len = strlen(s), zigSize = 2*numRows - 2;
	if (len == 0 || numRows == 1)
		return s;
	int numZigs = len / zigSize, remZigs = len % zigSize;
	for (int i = 0; i < numRows; i++) 
		rowCount[i] = 0;
	for (int i = 0; i < len; i++) 
		conS[i] = 0;
	//divide conS to each converted rows ie. compute rowStart[]
	//first count num of char in each row
	rowStart[0] = rowStart[numRows - 1] = numZigs;
	for (int i = 1; i < numRows -1; i++)
		rowStart[i] = 2*numZigs;
	if (remZigs/numRows > 0) {
		for (int i = 0; i < numRows; i++)
			rowStart[i]++;
		remZigs %= numRows;
		for (int i = numRows-2; remZigs > 0 && i>=0; remZigs--, i--)
			rowStart[i]++;
	}
	else {
		for (int i = 0; i < remZigs; i++)
			rowStart[i]++;
	}
	/*
	for (int i = 0; i < numRows; i++)
		printf("%d%c", rowStart[i], " \n"[i==numRows-1]);
	*/

	//then reduction rowStart
	for (int i = 1; i < numRows; i++)
		rowStart[i] += rowStart[i-1];
	conS[rowStart[numRows-1]] = 0;
	for (int i = numRows-1; i > 0; i--)
		rowStart[i] = rowStart[i-1];
	rowStart[0] = 0;

	//compute each char to new row and col
	int zigPos = 0, newRow;
	for (int i = 0; i < len; i++) {
		if (zigPos/numRows >0) 
			newRow = numRows - 2 - zigPos%numRows;
		else 
			newRow = zigPos;
		conS[rowStart[newRow]+rowCount[newRow]] = s[i];
		rowCount[newRow]++;
		zigPos = (zigPos+1)%zigSize;
	}
	return conS;
}
