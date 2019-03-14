//Warning. This is a wrong code but accepted by leetcode.
#include "maxPoints.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//type
typedef struct myPoint {
	Point p;
	int Num;
	int curID;
} myPoint;
typedef struct Line {
	int vertical; // vertical line
	myPoint *p1;
	myPoint *p2;
} Line;


//var
myPoint myPoints[maxN];
Line line[maxN*(maxN-1)/2];

//fun
Line computeTan(myPoint *p1, myPoint *p2) {
	Line ret;
	if (p1->p.x == p2->p.x)
		ret.vertical = 1;
	else
		ret.vertical = 0;
	if (p1->p.x > p2->p.x) {
		ret.p1 = p1;
		ret.p2 = p2;
	}
	else {
		ret.p1 = p2;
		ret.p2 = p1;
	}
	return ret;
}
int cmpP(const void *a, const void *b) {
	Point aa = *(Point *)a, bb = *(Point *)b;
	if (aa.x == bb.x)
		return aa.y > bb.y;
	return aa.x > bb.x;
}
int cmpL(const void *a, const void *b) {
	Line aa = *(Line *)a, bb = *(Line *)b;
	if (aa.vertical == 1 && bb.vertical == 1)
		return aa.p1->p.x - bb.p1->p.x;
	if (aa.vertical == 1 && bb.vertical != 1)
		return 1;
	if (aa.vertical !=1 && bb.vertical ==1)
		return -1;
	long long x1 = aa.p1->p.x, y1 = aa.p1->p.y, x2 = aa.p2->p.x, y2 = aa.p2->p.y;
	long long alp1 = bb.p1->p.x, bet1 = bb.p1->p.y, alp2 = bb.p2->p.x, bet2 = bb.p2->p.y;
    double k1 = ((double)(x1*y2 - x2*y1))/(x1-x2);
    double k2 = ((double)(alp1*bet2 - alp2*bet1))/(alp1-alp2);
    if ((y1-y2)*(alp1-alp2) == (x1-x2)*(bet1-bet2)) {
        if (k1 == k2)
            return 0;
        return k1 > k2 ? 1 : -1;
    }
    return (y1-y2)*(alp1-alp2) > (x1-x2)*(bet1-bet2) ? 1:-1;

	
	
}

int maxPoints(struct Point* points, int pointsSize) {
//	myPoint myPoints[pointsSize];
//	Line line[pointsSize*(pointsSize-1)/2];
//	printf("size = %lu %lu\n", sizeof(myPoints), sizeof(line));
	if (pointsSize == 0) return 0;
	if (pointsSize == 1) return 1;
	qsort(points, pointsSize, sizeof(Point), cmpP);
	Point temp = points[0];
	int mySize = 0, countP = 1;
	for (int i = 1; i < pointsSize; i++) {
		if (memcmp(&points[i], &temp, sizeof(Point))!=0) {
			myPoints[mySize].p = temp;
			myPoints[mySize].Num = countP;
			myPoints[mySize].curID = 0;
			countP = 1;
			mySize++;
			temp = points[i];
			continue;
		}
		countP++;
	}
	myPoints[mySize].p = temp;
	myPoints[mySize].Num = countP;
	mySize++;
	if (mySize == 1)
		return myPoints[0].Num;
/*	for (int i = 0; i < mySize; i++) {
		printf("xy = %d %d, num = %d\n", myPoints[i].p.x, myPoints[i].p.y, myPoints[i].Num);
	}
*/
	int numLine = 0;	
	for (int i = 0; i < mySize-1; i++)
		for (int j = i+1; j < mySize; j++)
			line[numLine++] = computeTan(&myPoints[i], &myPoints[j]);
	qsort(line, numLine, sizeof(Line), cmpL);
	
/*	
	for (int i = 0; i < numLine; i++)
		printf("line:%d:vert=%d, xy=%d %d, albe = %d %d\n",i,line[i].vertical, line[i].p1->p.x, line[i].p1->p.y, line[i].p2->p.x, line[i].p2->p.y);
*/		
	
	int curLine = 0, maxPcount = 0, curmaxPcount = 0, curID = 1;
	for (int i = 0; i < numLine; i++) {
		if (cmpL((void *)&line[curLine], (void *)&line[i]) !=0) {
			curLine = i;
			curID += 1;
			maxPcount = maxPcount > curmaxPcount ? maxPcount:curmaxPcount;
			curmaxPcount = line[i].p1->Num + line[i].p2->Num;
			line[i].p1->curID = curID;
			line[i].p2->curID = curID;
		} else {
			if (line[i].p1->curID != curID) {
				curmaxPcount += line[i].p1-> Num;
				line[i].p1->curID = curID;
			}
			if (line[i].p2->curID != curID) {
				curmaxPcount += line[i].p2-> Num;
				line[i].p2->curID = curID;
			}
		}
	}
	maxPcount = maxPcount > curmaxPcount ? maxPcount:curmaxPcount;
	return maxPcount;
}
