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

void ShellSort(SqList *L){
	int i, j;
	int increment = L->length;	

	do
	{
		increment = increment/3+1;

		for (i=increment+1; i<=L->length; i++){
			if (L->r[i] < L->r[i-increment]){
				L->r[0] = L->r[i];
			
				for (j=i-increment; j>0&&L->r[0]<L->r[j]; j-=increment){
					L->r[j+increment] = L->r[j];
				}	
	
				L->r[j+increment] = L->r[0];
			}
		}
	}while(increment>1);
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
	ShellSort(&a);

	for (i=1; i<=a.length; i++){
		printf("%d\n", a.r[i]);
	}
}