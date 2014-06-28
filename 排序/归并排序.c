#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int r[MAXSIZE+1];
	int length;
}SqList;

void Merge(int SR[], int TR[], int i, int m, int n){
	int j,k;
	for (j=m+1, k=i; i<=m && j<=n; k++){
		if (SR[i] < SR[j]){
			TR[k] = SR[i++];
		}
		else {
			TR[k] = SR[j++];
		}
	}

	while (i<=m){
		TR[k++] = SR[i++];
	}

	while (j<=n){
		TR[k++] = SR[j++];
	}
}

void MSort (int SR[], int TR1[], int s, int t){
	int m;
	int TR2[MAXSIZE+1];
	if (s == t){
		TR1[s] = SR[s];
	}	
	else {
		m = (s+t)/2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m+1, t);
		Merge(TR2, TR1, s, m, t);
	}
}

void MergeSort(SqList *L){
	MSort(L->r, L->r, 1, L->length);
}





void main()
{
	int i;
	SqList a;
	a.length = 10;
	srand(1);
	
	for (i=0; i<a.length+1; i++){
		a.r[i] = rand()%100;
	}
	
	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}

	printf("\n");
	MergeSort(&a);

	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}
}