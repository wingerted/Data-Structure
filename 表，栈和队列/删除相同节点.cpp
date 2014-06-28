#include <iostream>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
}LinkNode, *LinkList;

void CreateList(LinkList &L) {
	L = new LinkNode;
	L->next = NULL;
	LinkNode *p = L;

	int word;
	while (cin >> word) {
		p->next = new LinkNode;
		p = p->next;
		
		p->next = NULL;
		p->data = word;
	}
}

void PrintList(LinkList L) {
	L = L->next;

	while (L) {
		cout << L->data << endl;
		L = L->next;
	}
}

void DeleteSame(LinkList &L) {
	LinkNode *p = L->next;

	while (p) {
		LinkNode *q = p;

		while (q->next) {
			if (q->next->data == p->data) {
				LinkNode *r = q->next;
				q->next = r->next;
				delete r;			
			} else {
				q = q->next;
			}
		}

		p = p->next;
	}
}


int main()
{
	LinkList L = NULL;

	CreateList(L);

	PrintList(L);

	DeleteSame(L);

	PrintList(L);

	return 0;
}