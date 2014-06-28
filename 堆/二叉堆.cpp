#include <iostream>

using namespace std;

void InsertHeap()




int main()
{
	int heap[100];
	int size = 0;

	for (int i=0; i!=10; ++i) {
		int x;
		int j;
		cin >> x;
		for (j=++size; heap[j/2]>x; j/=2) {
			heap[j] = heap[j/2];
		}
		heap[j] = x;
	}




	return 0;
}