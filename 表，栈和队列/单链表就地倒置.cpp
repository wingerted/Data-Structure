#include <iostream>

using namespace std;

struct LNode {
	int data;
	LNode *next;
};

class LinkList {
private : 
	LNode *head;
public :
	LinkList() {
		head = new LNode;
		head->next = NULL;
	}

	void CreateList();

	void PrintList();

	void ReverseList();
};

void LinkList::CreateList() {
	LNode *p = head;

	int word;
	while (cin >> word) {
		LNode *r = new LNode;
		r->data = word;
		r->next = NULL;

		p->next = r;
		p = p->next;
	}
}

void LinkList::PrintList() {
	LNode *p = head->next;

	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
}

/***********·½·¨Ò»*************
void LinkList::ReverseList() {
	LNode *p = head->next;
	LNode *q = NULL;

	while (p) {
		LNode *r = p->next;
		p->next = q;
		q = p;
		p = r;
	}

	head->next = q;
}
*******************************/

void LinkList::ReverseList() {
	LNode *p = head->next->next;
	head->next->next = NULL;

	while (p) {
		LNode *q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}
		


int main() 
{
	LinkList L;

	L.CreateList();

	L.PrintList();

	L.ReverseList();

	L.PrintList();

	return 0;
}
