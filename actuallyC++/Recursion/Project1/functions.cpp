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
	std::cout << " Move Disk " << n << " from rod " << from_rod << " to rod " << to_rod <<" Value :"<<index<< std::endl;
	towerofhanoi(n - 1, aux_rod, to_rod, from_rod,index++);
	//index++;

}