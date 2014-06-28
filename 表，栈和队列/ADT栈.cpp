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
		cout << "已经到栈底" << endl;
		return -1;
	}

	return s.data[s.length--];
}

int main()
{
	setlocale(LC_ALL, "");
	Stack a;
	int x = 0;

	InitStack(a);

	cout << "请输入元素：" << endl;
	cin >> x;

	while (x != -1){
		PushStack(a, x);
		cout << "请输入元素：" << endl;
		cin >> x;
	}

	while (a.length >= 0){
		cout << PopStack(a) << endl;
	}

	return 0;
}