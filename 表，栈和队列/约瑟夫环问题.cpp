#include <iostream>

using namespace std;

struct LNode {
	int data;
	LNode *next;
};

class LinkList {
private : 
	LNode *tail;
public :
	LinkList() {
		tail = new LNode;
		tail->next = tail;
	}

	void CreateList(int n);

	void PrintList();

	void Joseph(int k);
};

void LinkList::CreateList(int n) {
	LNode *r = tail;
	for (int i=1; i!=n+1; ++i) {
		LNode *p = new LNode;
		p->data = i;
		p->next = tail;

		r->next = p;
		r = r->next;
	}

	tail = r;
}

void LinkList::PrintList() {
	LNode *p = tail->next->next;

	while (p != tail->next) {
		cout << p->data << endl;
		p = p->next;
	}
}

void LinkList::Joseph(int k) {
	LNode *p = tail->next;

	while (tail->next != tail) {
		LNode *d = p->next;
		if (d == tail->next) {
			d = d->next;
			p = p->next;
		}
		p->next = d->next;
		if (d == tail) {
			tail = p;
		}
		cout << d->data << " ";
		delete d;
		
		for (int i=0; i!=k; ++i) {
			p = p->next;

			if (p == tail->next) {
				p = p->next;
			}
		}		
	}

	cout << endl;
}

int main() 
{
	setlocale(LC_ALL, "");

	LinkList L;
	int n;
	int k;

	cout << "ÇëÊäÈënºÍk£º" << endl;
	cin >> n >> k;

	L.CreateList(n);

	L.PrintList();

	L.Joseph(k);

	return 0;
}