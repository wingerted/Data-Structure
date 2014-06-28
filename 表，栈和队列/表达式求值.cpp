#include <iostream>

using namespace std;

typedef struct {
	int data[100];
	int length;
}Stack;

void InitStack (Stack &s){
	s.length = -1;
}

void PushStack (Stack &s, int x){
	if (s.length > 99){
		cout << "超过最大栈空间" << endl;
		return ;
	}

	s.data[++s.length] = x;
}

int PopStack (Stack &s){
	if (s.length < 0){
		return '#';
	}

	return s.data[s.length--];
}

char GetTop (Stack &s){
	if (s.length < 0){
		return '#';
	}

	return s.data[s.length];
}

char Judge(char a, char b){
	if (b == '#'){
		return '>';
	}

	if (a == '\0'){
		return '<';
	}

	char mark[8][8] = {					
		'>', '=', '>', '>', ' ', '>', ' ', '>',
		'=', '>', '<', '<', ' ', '<', ' ', '<',
		'>', '<', '<', '>', ' ', '>', ' ', '<',
		'>', '<', '<', '<', ' ', '<', ' ', '<',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		'>', '<', '<', '<', ' ', '<', ' ', '<',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		'>', '<', '<', '>', ' ', '>', ' ', '<'
	};

	return mark[a%40][b%40];
}

int Operate(int a, char mark, int b){
	switch (mark){
		case '+' :	return a + b;
		case '-' :	return a - b;
		case '*' :	return a * b;
		case '/' :	return a / b;
		default	 :	return NULL;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	Stack OPND;
	Stack OPTR;
	char data[100];
	bool flag = true;
	char *p = NULL;

	InitStack(OPND);
	InitStack(OPTR); 

	cout << "请输入表达式：" << endl;
	cin >> data;
	p = data;

	while (*p != '\0'){
		if ('0'<=*p && *p<='9' && flag){
			PushStack(OPND, atoi(p));
			flag = false;
			p++;
		}else if ('0'>*p || *p>'9'){
			switch (Judge(*p, GetTop(OPTR))){
				case '>' :	PushStack(OPTR, *p);
							p++;
							break;
				case '=' :	PopStack(OPTR);
							p++;
							break;
				case '<' :	PushStack(OPND, Operate(PopStack(OPND), PopStack(OPTR), PopStack(OPND)));	
							break;				
			}			
			
			flag = true;
		}else{
			p++;
		}
	}

	while (GetTop(OPTR) != '#'){
		PushStack(OPND, Operate(PopStack(OPND), PopStack(OPTR), PopStack(OPND)));	
	}

	cout <<	PopStack(OPND) << endl;
	return 0;
}