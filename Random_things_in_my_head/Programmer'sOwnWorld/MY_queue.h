#pragma once
#include<Vector>
#include<iostream>

using namespace std;
class MY_queue
{
	static int rear;
	static int front;
	int size;
	MY_queue(int size);
	int* queue;

	//For putting the value in the queue
	void Enque(int value);
	//For taking out the value from the queue
	void Deque();
	//Printing The Values
	void PrintTheValue();
	void createtheQueue(int size)

	
};

