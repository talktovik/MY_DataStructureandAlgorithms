#include<stdio.h>
#include<iostream>
#include <cstdlib>
#include<string>
#include<vector>
extern int f[10];

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
/*
* Now the taylor series is doing alot of multiplications. and if you find out they are O(n^2) so we can do something better and come
* up with a solution which take less multiplication and thus executes faster.
*/
//Taylor series by Horner's Rule
//[Here we take the comman part and do computations thereafter.]

double Hornertaylor(int x, int n) {
// lets say x = 4 and n = 4
	static double hold = 1;

	if (n == 0) return hold;
	hold = (1 + x * hold / n );          // Main line of the function 
		return Hornertaylor(x, n - 1);
	
	
}

//Fibonacci series !! 
/*
series looks like [0 1 1 2 3 5 8 13 21]
this series starts with 0 and 1 and add the previous 2 terms  to find out the next one.
Like: 0 +1 = 1 and  1 +1 = 2 and 1 +2 = 3 and so on....
We have to write the recursive function for this! 
*/

/*
				|
				| 0						if n= 0
     fib(n) =	| 1						if n =1 
				|
				| fib(n-2) + fib(n-1)   if n>1
*/



int fibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}


/*More About the Fibonacci series
 Something Memorisation comes into picture.
 and there is a golden ratio kind of logic but that might leads to incorrect answer sometimes.
                                                  [0 1 1 2 3 5 8 13 21 34 ...........]
So since we see there are lot of functions we are calculating which we already calculated. Like fib(1) is calculateded a lot and so that fib(0)
So remove this we somehow want to impliment memorisation
*/                   
// And this recursive equation shows that time complexity is O(2^n) which is huge.
// So reason this is having so complexity is because this function is calling same thing multiple times and we call it excessive recursion
// to remove this we can memorise the function calls and before doing any call we must look over the [array] for example and check the value over there.
/*
For example we are calling things alot so we can declare an array of size (static array)fib[n] and put zero initially and whenever we compulte 
the value of any function call we update it over there as well like if fib(3) turns out to be 2 then what we do is fin[3] =2 and
in future whenever we require this value then we will look it up over there and make our work easier.

and clerly you observe the function calls made by after including the memorising method then you will find out its O(n) where n is the input provided.
 so we actually reduced the call from exponential to linear.
 


 There is slight difference in memorisation and dynamic programming. 
 Okay the array we are talking about there was(static array )fib[n]. we can make this array as global array because in case if we need fib(n) more than
 one time then it would be handly. !

*/

//iterative version of fibonacci series which runs on directly O(n) time


int iterfibo(int n) {	
	int firstprev = 0, secondprev = 1,sum=0 , i ; 
	if (n == 0) return 0;
	if (n == 1) return 1;
	for (i = 2; i < n; i++) {
		sum = firstprev + secondprev;
		firstprev = secondprev;
		secondprev = sum;
	}
	return sum;
}

int memorisationof_fibonacci(int n) {

	if (n <= 1)
	{ f[n] = n; 
	return n; }
	//now for n > 1:
	else {
		if (f[n - 2] == -1)
			f[n - 2] = memorisationof_fibonacci(n - 2); // we are checking the value directly , if not there we are calling the recursive call !
		if (f[n - 1] == -1)
			f[n - 1] == memorisationof_fibonacci(n - 1); // we are checking the value directly , if not there we are calling the recursive call !

		return f[n - 2] + f[n - 1];
	}
	/*for (int i = 0; i < n; i++) {
		printf("%d\n", f[i]);
	}*/
}

 















// combinations C(n,r)






//newly ACTIUALLY MEET

using namespace std;
void newly() {
	int t; cin >> t;
	for (int c = 0; c < t; c++) {
		string hour; string turn;
		cin >> hour; cin >> turn;
		int time_p = 0;
		if (turn == "PM" && hour.substr(0, 2) != "12") {
			time_p = time_p + 720;
		}
		if (!(turn == "AM" && hour.substr(0, 2) == "12")) {
			time_p = time_p + stoi(hour.substr(0, 2)) * 60;
		}
		time_p = time_p + stoi(hour.substr(3, 2));
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> hour; cin >> turn;
			int time_l = 0;
			if (turn == "PM" && hour.substr(0, 2) != "12") {
				time_l = time_l + 720;
			}
			if (!(turn == "AM" && hour.substr(0, 2) == "12")) {
				time_l = time_l + stoi(hour.substr(0, 2)) * 60;
			}
			time_l = time_l + stoi(hour.substr(3, 2));

			cin >> hour; cin >> turn;
			int time_r = 0;
			if (turn == "PM" && hour.substr(0, 2) != "12") {
				time_r = time_r + 720;
			}
			if (!(turn == "AM" && hour.substr(0, 2) == "12")) {
				time_r = time_r + stoi(hour.substr(0, 2)) * 60;
			}
			time_r = time_r + stoi(hour.substr(3, 2));

			if (time_l <= time_p && time_p <= time_r) {
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
		cout << "\n";
	}
}




//experiment with arrays 


void func2() {
	//vector<int,int > arr; this I tried!!

	vector<vector<int>> arr = {
		{1,2,3},
		{1,2,3},
		{1,2,43}


	};
	cout << arr[2][2];



}