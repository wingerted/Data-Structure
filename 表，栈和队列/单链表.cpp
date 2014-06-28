#include <iostream>

using namespace std;

typedef struct LNode{
	int elem;
	struct LNode *next;
}node, *list;

/**************************ɾ���ظ�****************************/
void De_REP(node *head){
	if (!head->next){
		return;
	}

	node *p = head->next;
	while (p->next){
		if (p->elem == p->next->elem){
			node *q = p->next;
			p->next = p->next->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
}

/**************************��������****************************/
void Insert_List(node *p, int elem){
	node *q = (node *)malloc(sizeof(node));
	q->elem = elem;
	q->next = NULL;
	
	p->next = q;
}

/**************************��������****************************/

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

/**************************�������****************************/
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

/************************���ϵĲ�����**************************/
list Make_OR(list a, list b)
{
	list c;								//����һ��������					
	c = (list)malloc(sizeof(node));
	c->next = NULL;
	list p = c;

	for (node *i=a->next; i; i=i->next){
		bool flag = true;
		
		for (node *j=b->next; j; j=j->next){
			if (j->elem == i->elem){		//Ԫ����ͬΪTrue,��ͬΪFalse
				flag = false;
				break;
			}
		}
		
		if (flag){
			Insert_List(p, i->elem);
			p = p->next;
		}
	}

	for (node *i=b->next; i; i=i->next){
		Insert_List(p, i->elem);
		p = p->next;
	}

	De_REP(c);

	return c;
}

/************************���ϵĽ�����**************************/
list Make_AND(list a, list b)
{
	list c;
	c = (list)malloc(sizeof(node));
	c->next = NULL;
	list p = c;

	for (node *i=a->next; i; i=i->next){
		bool flag = false;

		for (node *j=b->next; j; j=j->next){
			if (j->elem == i->elem){
				flag = true;
				break;
			}
		}

		if (flag){
			Insert_List(p, i->elem);
			p = p->next;
		}
	}


	return c;
}

/************************���ϵĲ�����**************************/
list Make_SUB(list a, list b)
{
	list c;
	c = (list)malloc(sizeof(node));
	c->next = NULL;
	list p = c;

	for (node *i=a->next; i; i=i->next){
		bool flag = false;
		
		for (list j=b->next; j; j=j->next){
			if (j->elem == i->elem){
				flag = true;
				break;
			}
		}

		if (!flag){
			Insert_List(p, i->elem);
			p = p->next;
		}
	}

	De_REP(c);

	return c;
}


/************************������ĳ���**************************/
int Length_List(list L){
	int length = 0;

	while (L->next){
		L = L->next;
		length++;
	}

	cout << "����Ϊ��" << length <<endl;
	
	return length;
}

/************************������Сֵ�ĵ�ַ**************************/
node* SelectMin(list L, int length){
	node *p = L->next;
	node *q = L->next;

	for (int i=0; i<length; i++){
		if (q->elem < p->elem){
			p = q;
		}
		q = q->next;
	}

	return p;
}

/************************ѡ������**************************/
void SelectSort_List(list L, int length)
{
	node *r = L;
	while (r->next){
		r = r->next;
	}

	for (int i=length; i>0; i--){
		node *q = SelectMin(L, i);
		node *p = L;
		
		while (p->next != q){
			p = p->next;
		}

		r->next = p->next;           //�ѵ�iС�����ݷ���β��֮��
		r = r->next;
		p->next = r->next;
		r->next = NULL;
	}

}

/************************ð������**************************/
void BubbleSort_List(list L, int length)
{
	for (int i=0; i<length; i++){
		node *p = L;
		node *q = p->next->next;
		
		for (int j=0; j<length-i-1; j++){
			 if (p->next->elem < q->elem){
				p->next->next = q->next;
				q->next = p->next;				
				p->next = q;
				q = q->next;
			}

			p = p->next;
			q = q->next;
		}
	}
}

/************************������**************************/
void Reverse_List(list L)
{
	node *q = NULL;
	node *p = L->next->next;
	L->next->next = NULL;
	
	while (p){
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

/*********************������K��Ԫ��***********************/
int LastK_List(list L, int k)
{
	node *p, *q, *r;
	int n = 0;
	p = L->next;
	r = L->next;
	for (int i=1; i<k; i++){
		r = r->next;
	}
	q = r;

	while (r){
		if (n >= k-1){
			p = q;
			q = r;
			n = 0;
		}
		r = r->next;
		n++;
	}

	if (n < k){
		for (int i=0; i<n-1; i++){
			p = p->next;
		}
		return p->elem;
	}
	return q->elem;
}


int main()
{
	setlocale(LC_ALL, "");
	list A;
//	list B;
	
	cout << "����������A��" << endl;
	Create_List(A);

/*	
	cout << "����������B��" << endl;
	Create_List(B);

	cout << "**************����A***************" << endl;
	Print_List(A);

	cout << "**************����B***************" << endl;
	Print_List(B);
	
	cout << "**************A��B***************" << endl;
	Print_List(Make_OR(A, B));

	cout << "**************A��B***************" << endl;
	Print_List(Make_AND(A, B));
	
	cout << "**************A��B***************" << endl;
	Print_List(Make_SUB(A, B));

	cout << "**************B��A***************" << endl;
	Print_List(Make_SUB(B, A));

	cout << "**************����A***************" << endl;
	Print_List(A);

	cout << "**************����A(ð�������)***************" << endl;
	BubbleSort_List(A, Length_List(A));
	Print_List(A);

	cout << "**************����A(ѡ�������)***************" << endl;
	SelectSort_List(A, Length_List(A));
	Print_List(A);

	cout << "**************����A����***************" << endl;
	Reverse_List(A);
	Print_List(A);
*/
	int x;
	cout << "�����ڼ�Ԫ�أ�" << endl;
	cin >> x;
	cout << "������"<< x << "��Ԫ��Ϊ��" << LastK_List(A, x) << endl;


	return 0;
}