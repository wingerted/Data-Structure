#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TNode {
	TNode *parent;
	int weight;
	TNode *left;
	TNode *right;
};

bool isShorter(const TNode &t1, const TNode &t2) {
	return t1.weight < t2.weight;
}

int main()
{
	vector<TNode> temp;

	TNode word;
	while (cin  >> word.weight) {
		word.left = NULL;
		word.right = NULL;
		word.parent = NULL;
		temp.push_back(word);
	}

	while (temp.size() != 1) {
		stable_sort(temp.begin(), temp.end(), isShorter);
		TNode *s1 = new TNode;
		s1->left = temp.front().left;
		s1->right = temp.front().right;
		s1->weight = temp.front().weight;
		temp.erase(temp.begin());

		TNode *s2 = new TNode;
		s2->left = temp.front().left;
		s2->right = temp.front().right;
		s2->weight = temp.front().weight;
		temp.erase(temp.begin());

		TNode *x = new TNode;
		x->parent = NULL;
		x->weight = s1->weight + s2->weight;
		x->left = s1;
		x->right = s2;

		s1->parent = x;
		s2->parent = x;

		temp.push_back(*x);
	}

	TNode *t = new TNode;

	*t = temp.back();

	return 0;
}