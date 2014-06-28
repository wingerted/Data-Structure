#include <iostream>

using namespace std;

typedef struct LNode{
	int elem;
	struct LNode *next;
}node, *list;


void Create_List(list &L)
{
	L = (list)malloc(sizeof(node));  //����ͷ���
	L->next = NULL;

	node *p = L;	   //ָ��ͷ���
	node *q = NULL;    //ָ���½��
	int x;             //����Ԫ��

	cout << "���������ݣ�����-1����" << endl;
	cin >> x;

	while (x != -1){
		q = (node *)malloc(sizeof(node));  
		q->elem = x;
		q->next = NULL;						

		p->next = q;
		p = p->next;
		
		cout << "���������ݣ�����-1����" << endl;
		cin >> x;
	}
}

void Print_List(list h)
{
	if (!h->next){
		cout << "û��Ԫ��" << endl;
		return;
	}

	while (h->next){
		h = h->next;
		cout << h->elem << "  ";
	}
	cout << endl;
}


int length(list l){
	int length = 0;

	l = l->next;

	while (l->next){
		length++;
	}
	
	return length;
}

int main()
{
	list a;
	int len;

	Create_List(a);

	len = length(a);
		
	cout << len;

	return 0;
}