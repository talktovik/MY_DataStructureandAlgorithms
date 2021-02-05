#include"Header.h"
int main() {
	std::cout << "START" << std::endl;
	int arr[] = { 6,3,5,3,9};
	//Bubble_sort(arr, 5);// This is passing the array with the starting address. The function decleration knows that fun() need integer value.
	Insertion_sort(arr, 5);

}