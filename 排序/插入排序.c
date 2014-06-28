#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int r[MAXSIZE+1];
	int length;
}SqList;


void InsertSort(SqList *L){
	int i,j;
	for (i=2; i<L->length; i++){
		if (L->r[i] < L->r[i-1]){
			L->r[0] = L->r[i];
			
			for (j=i-1; L->r[j]>L->r[0]; j--){
				L->r[j+1] = L->r[j];
			}
			L->r[j+1] = L->r[0];
		}
	}
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
	InsertSort(&a);

	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}
}