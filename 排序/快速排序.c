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

int Partition(SqList *L, int low, int high){
	int pivotkey;
	pivotkey = L->r[low];
	
	while (low < high){
		while (low<high && L->r[high]>=pivotkey){
			high--;
		}
		swap(L, low, high);
		
		while (low<high && L->r[low]<=pivotkey){
			low++;
		}
		swap(L, low, high);
	}
	
	return low;
}

void QSort(SqList *L, int low, int high){
	int pivot;
	if (low < high){
		pivot = Partition(L, low, high);
		QSort(L, low, pivot-1);
		QSort(L, pivot+1, high);
	}
}

void QuickSort(SqList *L){
	QSort(L, 1, L->length);
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
	QuickSort(&a);

	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}
}