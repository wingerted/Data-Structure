#include <iostream>
#include <string>

using namespace std;

typedef struct TNode {
	char data;
	struct TNode *left;
	struct TNode *right;
}TNode, *BiTree;

void CreateTree(BiTree &T) {
	char c;
	cin >> c;
	if (c != '#') {
		T = new TNode;
		T->left = NULL;
		T->right = NULL;
		T->data = c;
		
		CreateTree(T->left);
		CreateTree(T->right);
	}
	return;
}


/***********************************
void PreOrder(BiTree t) {
	BiTree stack[1000];
	int top = 0;

	while (t || top!=0) {
		while (t) {
			cout << t->data << " ";
			stack[top++] = t;
			t = t->left;
		}
		if (top != 0) {
			t = stack[--top];
			t = t->right;
		}
	}

	cout << endl;
}
************************************/
void LevOrder(BiTree T) {
	BiTree queue[1000];
	int rear = 0;
	int top = 0;

	queue[rear++] = T;
	while (top != rear) {
		TNode *p = queue[top++];
		cout << p->data << " ";
		if (p->left) {
			queue[rear++] = p->left;
		}
		if (p->right) {
			queue[rear++] = p->right;
		}
	}

	cout << endl;
}

void PreOrder(BiTree T) {
	BiTree stack[1000];
	int top = 0;
	BiTree p = NULL;

	do {
		while (T) {
			cout << T->data << " ";
			stack[top++] = T;
			T = T->left;
		}

		while (top != 0) {
			T = stack[top-1];

			if (T->right == NULL) {
				top--;
				p = T;
			} else if (T->right == p) {
				top--;
				p = T;
			} else {
				T = T->right;
				break;
			}
		}
	}while (top != 0);

	cout << endl;
}

void InOrder(BiTree T) {
	BiTree stack[1000] = {0};
	int top = 0;	
	BiTree p = NULL;

	do {
		while (T) {
			stack[top++] = T;
			T = T->left;
		}

		while (top != 0) {
			T = stack[top-1];

			if (T->right == NULL) {
				cout << T->data << " ";
				p = T;
				top--;
			} else if (p == T->right) {
				p = T;
				top--;
			} else {
				cout << T->data << " ";
				T = T->right;
				break;
			}
		}
		
	}while (top != 0);

	cout << endl;
}

void PostOrder(BiTree T) {
	BiTree stack[1000];
	int top = 0;
	BiTree p = NULL;
	
	do {
		while (T) {
			stack[top++] = T;
			T = T->left;
		}

		while (top != 0) {
			T = stack[top-1];
			
			if (T->right == NULL) {
				cout << T->data << " ";
				p = T;
				top--;
			} else if (p == T->right) {
				cout << T->data << " ";
				p = T;
				top--;
			} else {
				T = T->right;
				break;
			}
		}
	}while (top != 0);

	cout << endl;
}

int main()
{
	BiTree t = NULL;

	CreateTree(t);
	
	PreOrder(t);
	InOrder(t);
	PostOrder(t);
	LevOrder(t);
	

	return 0;
}