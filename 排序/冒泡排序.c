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

void BubbleSort0(SqList *L){
	int i,j,c,d;
	c = 0;
	d = 0;
	for (i=1; i<L->length; i++){
		for (j=i+1; j<L->length; j++){
			c++;
			
			if (L->r[i] > L->r[j]){
				swap(L, i, j);
				d++;
			}
		}
	}
	printf("比较%d次,交换%d次\n", c, d);
}

void BubbleSort(SqList *L){
	int i,j,c,d;
	c = 0;
	d = 0;
	
	for (i=1; i<L->length; i++){
		for (j=L->length-1; j>=i; j--){
			c++;
			if (L->r[j] > L->r[j+1]){
				swap(L, j, j+1);
				d++;
			}
		}
	}
	printf("比较%d次,交换%d次\n", c, d);
}

void BubbleSort1(SqList *L){
	int i,j,c,d;
	int flag = 1;
	c = 0;
	d = 0;
	
	for (i=1; i<L->length&&flag==1; i++){
		flag = 0;
		for (j=L->length-1; j>=i; j--){
			c++;
			if (L->r[j] > L->r[j+1]){
				swap(L, j, j+1);
				d++;
				flag = 1;
			}
		}
	}
	printf("比较%d次,交换%d次\n", c, d);
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
	BubbleSort(&a);

	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}
}