#include<stdio.h>
#include<iostream>

int justarandomfunctioname(int i) {
	if (i == 1)
		return 1;
	else
		return  i + justarandomfunctioname(i - 1);

} //declaration
int factorial(long int i) {
	if (i == 1)
		return 1;
	else
		return i * factorial(i - 1);
}

void towerofhanoi(int n, char from_rod, char to_rod, char aux_rod, int index) {
// n is here no of disks 
	if (n == 1) {
		//index++;
		std::cout << " Move the disk {1} from rod " << from_rod << " to rod " << to_rod<<"value :"<< index << std::endl;
		return;
	}

	towerofhanoi(n - 1, from_rod, aux_rod, to_rod, index++);
	//index++;
	std::cout << " Move Disk " << n << "from rod " << from_rod << " to rod " << to_rod <<" Value :"<<index<< std::endl;
	towerofhanoi(n - 1, aux_rod, to_rod, from_rod,index++);
	//index++;

}
//tree recursion
void treefun(int n) {
	if (n > 0) {
		std::cout << n ;
		treefun(n-1);
		treefun(n-1);
	
	}
}
int nestedrecursion(int n ) {
	if (n > 100)
		return n - 10;
	return nestedrecursion(  nestedrecursion(n + 11));
}

int powerfun(int base, int ex) {
	if (ex == 1)
		return base;
	if (ex == 0)
		return 0;
	else 
		return base* powerfun(base, ex-1);
}

//int taylor(int i) {
//	int power = 0, fact= 0,thecall =0, thefinalval = 0 ;
//	power=powerfun(i, i);
//	fact = factorial(i);
//	thefinalval = power / fact;
//	//thecall = taylor(i-1);
//	return thefinalval + taylor(i - 1);
//} 


/*Write the new taylor function here */
//the taylor series is something like 

/*
* e^x = 1 + x/1 + x^2/2! + x^3 /3! .....
* 
*/
//here according to the instructor we need the static variables.

/*
thinking of taylor series
means if there is a tyalor function then it must take two values.
like => taylor(x,4)
where it says like x^4/4! and keep decreasing like
taylor(x,4) + return value
|
taylor(x,3) + return value 
|
taylor(x,2) + return value
|
taylor(x,1) + return value 
|
taylor(x,0) Lets say it would return 0


*/

double taylor(int x, int po) {
	if (po > 0) {
		double powof = powerfun(x, po);
		double fact = factorial(po);
		double res = (double) powof / fact;
		return taylor(x, po - 1) + res;
	}
	else return 1;
}


//Different version of taylor [modern]
//something called using the static variables



//for more clarity we need just say f= factorial, r = result and 
// p = doing the power.
double moditaylor(int x, int n) {
	static double p = 1, f = 1;
	double r;
	
	if (n == 0) return 1;
	r = moditaylor(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p / f;
	

}
