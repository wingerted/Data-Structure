#include <iostream>

using namespace std;

typedef struct {
	int r;
	int m;
	int n;
}AKM;

int akm(AKM x){
	AKM cao[40000];
	int length = 0;
	cao[0].r = 0;
	cao[0].m = x.m;
	cao[0].n = x.n;
	
	while (length!=0 || cao[length].r==0){
		if (cao[length].m == 0){
			if (length == 0){
				cao[length].r = cao[length].n+1;
			}else{
				cao[length-1].n =  cao[length].n+1;
				length--;
			}
		}else if (cao[length].n == 0){
			cao[length].m--;
			cao[length].n = 1;
		}else{
			cao[length].m--;
			cao[length+1].m = cao[length].m+1;
			cao[length+1].n = cao[length].n-1;
			cao[length+1].r = cao[length].r;
			length++;
		}
	}
	return cao[length].r;
}

int main()
{
	AKM x;

	cout << "Input M and N :" << endl;
	cin >> x.m >> x.n;

	cout << akm(x) << endl;

	return 0;
}

/*
typedef struct {
	AKM data[20000];
	int length;
}Stack;

void InitStack(Stack &S){
	S.length = -1;
}

void PushStack(Stack &S, AKM x){
	S.data[++S.length] = x;
}

AKM PopStack(Stack &S){
	return S.data[S.length--];
}

AKM GetTop(Stack S){
	return S.data[S.length];
}

*/
/*
int akm(int m, int n){
	if (m == 0){
		return n+1;
	}else if (n == 0){
		return akm(m-1, 1);
	}else{
		return akm(m-1, akm(m, n-1));
	}
}
*/

/*
AKM akm(AKM x){
	Stack S;
	InitStack(S);
	x.r = 0;
	PushStack(S, x);
	
	while (S.length!=0 || GetTop(S).r==0){
		AKM x1 = PopStack(S);
		
		if (x1.m == 0){
			if (S.length == -1){
				x1.r = x1.n+1;
				PushStack(S, x1);
			}else{
				AKM x2 = PopStack(S);
				x2.n = x1.n+1;
				PushStack(S, x2);
			}
		}else if (x1.n == 0){
			x1.m = x1.m-1;
			x1.n = 1;
			PushStack(S, x1);
		}else{
			x1.m--;
			PushStack(S, x1);
			x1.m++;
			x1.n--;
			PushStack(S, x1);
		}
	}
	return PopStack(S);
}
*/








/*
int akm(int m, int n){
	Stack S;
	InitStack(S);
	int r = 0;
	PushStack(S, (int)&r);
	PushStack(S, m);
	PushStack(S, n);

top:
	if (S.length == 0){
		return r;
	}

	int n1 = PopStack(S);
	int m1 = PopStack(S);
	int *pr = (int*)PopStack(S);
	if (m1 == 0){
		*pr = n1+1;
		PushStack(S, n1+1);
		goto top;
	}else if (n1 == 0){
		PushStack(S, (int)pr);
		PushStack(S, m1-1);
		PushStack(S, 1);
		goto top;
	}else{
		PushStack(S, (int)pr);
		PushStack(S, m1-1);
		PushStack(S, (int)pr);
		PushStack(S, m1);
		PushStack(S, n1-1);
		goto top;
	}
}
*/
