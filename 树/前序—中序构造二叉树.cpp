#include <iostream>
#include <string>

using namespace std;

typedef struct TreeNode {
	char data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode, *Tree;

void CreateTree(Tree &T, string pre, string candidate, int i=0) {
	if (pre.size() == i) {
			return;
	}
	
	while (candidate.find(pre[i]) == -1) {
		++i;
		if (pre.size() == i) {
			return;
		}
	}

	int s = candidate.find(pre[i]);
	
	T = new TreeNode;
	T->left = NULL;
	T->right = NULL;
	T->data = pre[i];

	CreateTree(T->left, pre, candidate.substr(0, s), i+1);
	CreateTree(T->right, pre, candidate.substr(s), i+1);	
}


int main()
{
	setlocale(LC_ALL, "");
	Tree T = NULL;

	string pre;
	string mid;

	cout << "输入前序遍历：" << endl;
	cin >> pre;

	cout << "输入中序遍历：" << endl;
	cin >> mid;

	CreateTree(T, pre, mid);



	return 0;
}