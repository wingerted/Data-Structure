#include <iostream>

using namespace std;

typedef struct LNode{
	int elem;
	struct LNode *next;
}node, *list;

/**************************删除重复****************************/
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

/**************************插入数据****************************/
void Insert_List(node *p, int elem){
	node *q = (node *)malloc(sizeof(node));
	q->elem = elem;
	q->next = NULL;
	
	p->next = q;
}

/**************************建立链表****************************/

void Create_List(list &L)
{
	L = (list)malloc(sizeof(node));  //建立头结点
	L->next = NULL;

	node *p = L;	   //指向头结点
	node *q = NULL;    //指向新结点
	int x;             //数据元素

	cout << "请输入数据，输入-1结束" << endl;
	cin >> x;

	while (x != -1){
		q = (node *)malloc(sizeof(node));  
		q->elem = x;
		q->next = NULL;						

		p->next = q;
		p = p->next;
		
		cout << "请输入数据，输入-1结束" << endl;
		cin >> x;
	}
}

/**************************输出链表****************************/
void Print_List(list h)
{
	if (!h->next){
		cout << "没有元素" << endl;
		return;
	}

	while (h->next){
		h = h->next;
		cout << h->elem << "  ";
	}
	cout << endl;
}

/************************集合的并运算**************************/
list Make_OR(list a, list b)
{
	list c;								//建立一个新链表					
	c = (list)malloc(sizeof(node));
	c->next = NULL;
	list p = c;

	for (node *i=a->next; i; i=i->next){
		bool flag = true;
		
		for (node *j=b->next; j; j=j->next){
			if (j->elem == i->elem){		//元素相同为True,不同为False
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

/************************集合的交运算**************************/
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

/************************集合的差运算**************************/
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


/************************求链表的长度**************************/
int Length_List(list L){
	int length = 0;

	while (L->next){
		L = L->next;
		length++;
	}

	cout << "长度为：" << length <<endl;
	
	return length;
}

/************************返回最小值的地址**************************/
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

/************************选择排序**************************/
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

		r->next = p->next;           //把第i小的数据放在尾巴之后
		r = r->next;
		p->next = r->next;
		r->next = NULL;
	}

}

/************************冒泡排序**************************/
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

/************************链表倒置**************************/
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

/*********************倒数第K个元素***********************/
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
	
	cout << "请输入链表A：" << endl;
	Create_List(A);

/*	
	cout << "请输入链表B：" << endl;
	Create_List(B);

	cout << "**************集合A***************" << endl;
	Print_List(A);

	cout << "**************集合B***************" << endl;
	Print_List(B);
	
	cout << "**************A并B***************" << endl;
	Print_List(Make_OR(A, B));

	cout << "**************A交B***************" << endl;
	Print_List(Make_AND(A, B));
	
	cout << "**************A差B***************" << endl;
	Print_List(Make_SUB(A, B));

	cout << "**************B差A***************" << endl;
	Print_List(Make_SUB(B, A));

	cout << "**************集合A***************" << endl;
	Print_List(A);

	cout << "**************集合A(冒泡排序后)***************" << endl;
	BubbleSort_List(A, Length_List(A));
	Print_List(A);

	cout << "**************集合A(选择排序后)***************" << endl;
	SelectSort_List(A, Length_List(A));
	Print_List(A);

	cout << "**************集合A倒置***************" << endl;
	Reverse_List(A);
	Print_List(A);
*/
	int x;
	cout << "求倒数第几元素？" << endl;
	cin >> x;
	cout << "倒数第"<< x << "个元素为：" << LastK_List(A, x) << endl;


	return 0;
}