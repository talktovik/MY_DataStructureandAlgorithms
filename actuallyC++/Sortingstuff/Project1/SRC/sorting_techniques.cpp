#include<stdio.h>

void printing(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("\n%d", A[i]);
	}
}


void swap(int* a, int* b) {
	int temp;
	//*a = temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Bubble_sort(int a[],int n) {
	int howmuch = 0;
	int swapped, i, j;
	for (i = 0; i < n; i++){  // this is representing the passes
		swapped = 0;// The variable swapped would here to check if the list is already sorted.
		++howmuch;
		for (j = 0; j < n - i - 1; j++) { //because in every pass one element would reduce so we are doing (n-1-i) here 
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0) {
			printf("List is sorted\n");
			printf("Number of passes required are %d\n", howmuch);
			break;
		}
	}
	for (  i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}


}
void Insertion_sort(int A[], int n) {
	int j, index, holding_element;
	for (int index = 1; index < n; index++) {
		j = index - 1;
		holding_element = A[index];
		while (j > -1 && A[j] > holding_element) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = holding_element;
	}
	printing(A, n);
}

void selectionsort(int a[], int n) {
	int ptr, srcptr;
	for (int i = 0; i < n; i++) {
		ptr = i;
		srcptr = i;
		if a[ptr]
	}

}




