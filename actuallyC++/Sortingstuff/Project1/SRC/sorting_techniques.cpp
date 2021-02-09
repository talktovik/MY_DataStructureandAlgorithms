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
		if (a[ptr] < a[srcptr]){
			swap(&a[ptr], &a[srcptr]);
			//ptr
		}
	}

}


//void testing() {
//	bool beginsAtSide(const _FaceGrid & sideGrid1,
//		const _FaceGrid & sideGrid2,
//		SMESH_ProxyMesh::Ptr proxymesh)
//	{
//		const TNodeColumn& col0 = sideGrid2._u2nodesMap.begin()->second;
//		const TNodeColumn& col1 = sideGrid2._u2nodesMap.rbegin()->second;
//		const SMDS_MeshNode* n00 = col0.front();
//		const SMDS_MeshNode* n01 = col0.back();
//		const SMDS_MeshNode* n10 = col1.front();
//		const SMDS_MeshNode* n11 = col1.back();
//		const SMDS_MeshNode* n = (sideGrid1._u2nodesMap.begin()->second)[0];
//		if (proxymesh)
//		{
//			n00 = proxymesh->GetProxyNode(n00);
//			n10 = proxymesh->GetProxyNode(n10);
//			n01 = proxymesh->GetProxyNode(n01);
//			n11 = proxymesh->GetProxyNode(n11);
//			n = proxymesh->GetProxyNode(n);
//		}
//		return (n == n00 || n == n01 || n == n10 || n == n11);
//	}
//}
//
//
//
//}
//

//
//using namespace vik;
//
//
