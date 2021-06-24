#include "MY_queue.h"


/*
I guess this is not the entirely correct !
*/

 MY_queue::MY_queue(int size) 
{
	 this->size = size;
	 this->rear = 0;
	 this->front = 0;
	 createtheQueue(size);
}

 void MY_queue::Enque(int value)
 {
	//Insertion Happens From the rear
	 if (rear != sizeof(int) * size)
	 {
	 queue[rear] = value;
	 rear++;
	 }
	 else 
	 {
		 cout << "The Queue is actually Full" << endl;
	 }
	 
 }
 void MY_queue::Deque() 
 {
	 //whenever we call this function just delete the index pointed by Front.
	 if (front > 0) {
	 queue[front] = 0;
	 front--;
	 }
	 else 
	 {
		 cout << "Maybe the queue is empty. Print the value" << endl;
	 }
 
 }
 void MY_queue::createtheQueue(int size)
 {
	 queue = (int*)malloc(sizeof(int) * size);
 }