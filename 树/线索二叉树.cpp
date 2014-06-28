#include <iostream>

using namespace std;

typedef struct TNode {
	char data;
	bool ltag;
	bool rtag;
	TNode *left;
	TNode *right;
}TNode, *BiTree;

void CreateTree(BiTree &T) {
	char c;
	cin >> c;
	
	if (c != '#') {
		T = new TNode;
		T->ltag = false;
		T->rtag = false;
		T->left = NULL;
		T->right = NULL;

		T->data = c;

		CreateTree(T->left);
		CreateTree(T->right);
	}
}

void InThreading(TNode *p, TNode *pre) {
	if (p) {
		InThreading(p->left, pre);
		if (!p->left) {
			p->ltag = true;
			p->left = pre;
		}
		if (!pre->right) {
			pre->rtag = true;
			pre->right = p;
		}
		pre = p;
		InThreading(p->right, pre);
	}
}

void InOrderThreading(BiTree &Thrt, BiTree T) {
	Thrt = new TNode;
	Thrt->rtag = true;
	Thrt->right = Thrt;
	Thrt->ltag = false;

	if (!T) {
		Thrt->left = Thrt;
	} else {
		Thrt->left = T;
		TNode *pre = Thrt;
		InThreading(T, pre);
		pre->rtag = true;
		pre->right = Thrt;
		Thrt->right = pre;
	}
}

int main()
{
	BiTree T;
	BiTree Thrt;

	CreateTree(T);

	InOrderThreading(Thrt, T);

	return 0;
}