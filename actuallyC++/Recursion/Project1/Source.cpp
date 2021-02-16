#include "function.h"

int index;
////////////////////////////////////////
// Global array: 
int f[10]; // this would mimic the global array actually

int main() {
	//filling the entire array with -1
	for (int i = 0; i < 10; i++) {
		f[i] = -1;
	}

	//have to call the function for taylor series.

	//double val = taylor(1, 10);
	//approved by github hence the code is running good.
	//double val = Hornertaylor(1, 10); //taylor(1,10);

	//this modified version is also working same.
	//Lets have the logic then
	// int gal = fibo(9);
	//int gal = memorisationof_fibonacci(6);
	//newly();
	func2();
	//std::cout << gal;

}