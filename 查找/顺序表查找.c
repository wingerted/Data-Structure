int Sequential_Search(int *a, int n, int key){
	int i;

	for (i=0; i<n; i++){
		if(a[i] == key){
			return i;
		}
	}

	return 0;
}

int Sequential_Search1 (int *a, int n, int key){
	int i = n;
	a[0] = key;

	while (a[i] != key){
		i--;
	}

	return i;
}


