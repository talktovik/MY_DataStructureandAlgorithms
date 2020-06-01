//stack implementation with array!

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int a[MAX];
int top;

void initializeStack();
int isEmpty();
int isFull();
int size();
int peek();
void push(int x);
int pop();
void display();


int main()
{
	int choice,x;
	initializeStack();

	while(1)
	{
		printf("1.Push a Element on the Stack\n");
		printf("2.pop a Element from the stack\n");
		printf("3. display the top Element\n");
		printf("4.display all the stack Elements\n");
		printf("5.Display Size of the stack\n");
		printf("6.Quit\n");
		printf("Enter a choice:   \n");
		scanf("%d",&choice);
		if(choice == 6)
			break;
		switch(choice)
		{
			case 1:
			printf("Enter the Element to be pushed: \n");
			scanf("%d",&x);
			push(x);
			break;
			case 2:
			x = pop();
			printf("Popped Element is :  %d\n",x );
			break;
			case 3:
			printf("Element on the peek is: %d \n",peek() );
			break;
			case 4:
			display();
			break;
			case 5:
			printf("Size of the Stack is : %d\n",size() );
			break;
			default:
			printf("Wrong Choice\n");
		}
		printf("\n");
	}
}

void initializeStack()
{
	top = -1;
}
int size()
{
	return top +1;
}
int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}
int isFull()
{
	if(top == MAX-1)
		return 1;
	else
		return 0;
}
void push(int x)
{
	if(isFull())
	{
		printf("stackoverflow\n");
		return;
	}
	top = top + 1 ;
	a[top] = x;

}
int pop()
{
	int x; 
	if(isEmpty())
	{
		printf("stackoverflow\n");
		exit(1);

	}
	x = a[top];
	top = top -1 ;
	return x;

}
int peek()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);	
	}
	return a[top];
}
void display()
{
	int i;
	printf("top : %d\n",top );
	if(isEmpty()){
		printf("Stack is Empty\n");
		return;
	}
	printf("Stack is:  \n");
	for(i = top; i>=0 ; i--)
		printf("%d\n",a[i]);
	printf("\n");





}



