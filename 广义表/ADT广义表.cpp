#include <iostream>

using namespace std;

typedef enum {
	ATOM,
	LIST
}ElemTag;

typedef struct GLNode {
	ElemTag tag;
	union {
		int atom;
		struct {
			struct GLNode *hp;
			struct GLNode *tp;
		}ptr;
	};
}*GList;

int main()
{
	return 0;
}