#include <iostream>

using namespace std;

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode, *SearchTree;

SearchTree MakeEmpty(SearchTree T) {
	if (T) {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
		
	return NULL;
}

void InsertTree(SearchTree &T, int x) {
	if (!T) {
		T = (SearchTree)malloc(sizeof(TreeNode));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	} else if (x < T->data) {
		InsertTree(T->left, x);
	} else {
		InsertTree(T->right, x);
	}
}

void PrintTree(SearchTree T){
	if (T) {
		PrintTree(T->left);
		cout << T->data << endl;
		PrintTree(T->right);		
	}
}

void IsSameTree(SearchTree T1, SearchTree T2, bool &flag) {
	if (flag){
		return;
	}

	if (T1->data!=T2->data ||
		T1->left&&!(T2->left) || 
		!(T1->left)&&T2->left ||
		T1->right&&!(T2->right) ||
		!(T1->right)&&T2->right 
		) {
			cout << "不同" <<endl;
			flag = true;
			return;
	} else if (!(T1->left)&&!(T2->left)) {
		if (T1->right && T2->right) {
			IsSameTree(T1->right, T2->right, flag);
		}
	} else if (!(T1->right)&&!(T2->right)) {
		if (T1->left && T2->left) {
			IsSameTree(T1->left, T2->left, flag);
		}
	} else {
		IsSameTree(T1->left, T2->left, flag);
		IsSameTree(T1->right, T2->right, flag);
	}

	if (!flag) {
		cout << "相同" << endl;
	}
}




int main()
{
	setlocale(LC_ALL, "");

	SearchTree T1 = NULL;
	SearchTree T2 = NULL;
	int x;
	bool flag = false;


	for (int i=0; i<5; ++i) {
		cout << "输入元素：" << endl;
		cin >> x;
		InsertTree(T1, x);
	}

	cout << endl;

	for (int i=0; i<5; ++i) {
		cout << "输入元素：" << endl;
		cin >> x;
		InsertTree(T2, x);
	}

	IsSameTree(T1, T2, flag);

//	PrintTree(T);
	
	return 0;
}
