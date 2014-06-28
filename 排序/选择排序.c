#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int r[MAXSIZE+1];
	int length;
}SqList;

void swap (SqList *L, int i, int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void SelectSort(SqList *L){
	int i, j, min;
	int c = 0;
	for (i=1; i<L->length; i++){
		min = i;
		
		for (j=i+1; j<=L->length; j++){
			if (L->r[min] > L->r[j]){
				min = j;
			}
		}
		if (i != min){
			swap(L, min, i);
			c++;
		}
	}
	printf("½»»»%d´Î\n", c);
}
	

void main()
{
	int i;
	SqList a;
	a.length = 10;
	srand(1);
	
	for (i=0; i<a.length+1; i++){
		a.r[i] = rand()%10;
	}
	
	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}

	printf("\n");
	SelectSort(&a);

	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}
}