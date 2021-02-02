#include<stdio.h>

int fun(int i){
	if( i == 1)
		return 1;
	else
		return  i +fun(i -1);

} //declaration
int factorial (int i){
	if(i == 1)
		return 1;
	else 
		return i* fun(i-1);
}
int main () {

	int a ;
	a = factorial(10);
	printf("%d\n",a);
}