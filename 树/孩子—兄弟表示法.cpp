#include <iostream>
#include <string>

using namespace std;

typedef struct TreeNode {
	char data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSibling;
}TreeNode, *Tree;


string::iterator CreateTree(Tree &T, string &data, string::iterator iter) {
	T = new TreeNode;
	Tree p = T; 

	p->firstChild = NULL;
	p->nextSibling = NULL;

	for (; iter!=data.end(); ++iter) {
		if (*iter == '(') {
			iter = CreateTree(p->firstChild, data, iter+1);
		} else if (*iter == ',') {
			p->nextSibling = new TreeNode;
			p = p->nextSibling;
			p->firstChild = NULL;
			p->nextSibling = NULL;
		} else if (*iter == ')') {
			return iter;
		} else {
			p->data = *iter;
		}
	}
	return iter;
}

int main()
{
	Tree T = NULL;
	string data;

	cout << "ÊäÈëÊı¾İ" << endl;
	cin >> data;

	CreateTree(T, data, data.begin()); 

	return 0;
}
