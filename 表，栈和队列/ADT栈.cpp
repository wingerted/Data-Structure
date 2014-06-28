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
		cout << "�������ջ�ռ�" << endl;
		return ;
	}

	s.data[++s.length] = x;
}

int PopStack (Stack &s){
	if (s.length < 0){
		cout << "�Ѿ���ջ��" << endl;
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

	cout << "������Ԫ�أ�" << endl;
	cin >> x;

	while (x != -1){
		PushStack(a, x);
		cout << "������Ԫ�أ�" << endl;
		cin >> x;
	}

	while (a.length >= 0){
		cout << PopStack(a) << endl;
	}

	return 0;
}