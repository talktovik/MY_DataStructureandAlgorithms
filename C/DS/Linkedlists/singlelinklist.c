#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

struct node *createList(struct node *start);
void displayList(struct node *start);
void countNodes(struct node *start);
void search(struct node *start, int x);
struct node *insertInBeginning(struct node *start ,int data);
void insertAtEnd(struct node *start ,int data);
void insertAfter(struct node *start ,int data,int x);
struct node *insertBefore(struct node *start, int data, int x);
struct node *insertAtPosition(struct node *start, int data, int k);
struct node *deleteNode(struct node *start, int data);
struct node *reverseList(struct node *start);


int main()
{
	struct node *start = NULL;
	int choice,data,x,k;
	start = createList(start);

	while(1)
	{
		printf("\n");
		printf("1.displayList\n");
		printf("2.Count the number of nodes\n");
		printf("3.search for an element\n");
		printf("4.Add to empty list/ Add at Beginning\n");
		printf("5.Add a node at the end of the list\n");
		printf("6.Add a node after a specified node\n");
		printf("7.Add a node before a specified node\n");
		printf("8.Add a node at s given Position\n");
		printf("9.delete a node\n");
		printf("10.Reverse the list\n");

		printf("Enter your choice:");
		scanf("%d",&choice);

		if (choice == 11)
			break;

		switch(choice)
		{
			case 1:
			displayList(start);
			break;
			case 2:
			countNodes(start);
			break;
			case 3:
			printf("Enter the element to be searched: ");
			scanf("%d",&data);
			search(start,data);
			break;
			case 4:
			printf("Enter the element to be inserted: ");
			scanf("%d",&data);
			start =insertInBeginning(start,data);
			break;
			case 5:
			printf("Enter the element to be inserted: ");
			scanf("%d",&data);
			insertAtEnd(start,data); 
			break;
			case 6:
			printf("Enter the element to be inserted: ");
			scanf("%d",&data);
			printf("Enter the element after which to insert");
			scanf("%d",&x);
			insertAfter(start,data,x);
			break;
			case 7:
			printf("Enter the element to be Inserted: ");
			scanf("%d",&data);
			printf("Enter the element before which to insert");
			scanf("%d",&x);
			start= insertBefore(start,data,x);
			break;
			case 8:
			printf("Enter the element to be Inserted: ");
			scanf("%d",&data);
			printf("Enter the position on which to insert");
			scanf("%d",&k);
			start= insertAtPosition(start,data,k);
			break;
			case 9:
			printf("Enter the element to be Deleted ");
			scanf("%d",&data);
			start= deleteNode(start,data);
			break;
			case 10:
			start= reverseList(start);
			break;
			default:
			printf("WrongChoice");


		}
	}
}//  end of the main()


struct node *createList(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes:  ");
	scanf("%d",&n);
	if(n == 0)
		return start;

	printf("Enter the first element to be inserted:  ");
	scanf("%d",&data);
	start = insertInBeginning(start,data);
	for(i = 2; i<= n; i++)
	{
		printf("Enter the next element to be inserted:  ");
		scanf("%d", &data);
		insertAtEnd(start,data);
	}
	return start;
}//end of the function createList

struct node *insertInBeginning(struct node *start , int data)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp -> info = data;

	temp -> link = start;
	start = temp;

	return start;
}// end of Function
void insertAtEnd(struct node *start, int data)
{
	struct node *p,*temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp -> info = data;

	p= start ;
	while(p->link != NULL)
		p = p -> link;

	p -> link = temp;
	temp ->link = NULL;
}//end of function

void displayList(struct node *start)
{
	struct node *p;
	if (start == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	printf("List is:   ");
	p = start;
	while(p!= NULL)
	{
		printf("%d ",p -> info);
		p = p -> link;
	}
		printf("\n");
}//end of Display Function !!!

void countNodes(struct node *start)
{
	int n = 0;
	struct node *p = start;
	while(p != NULL)
	{
		n++;
		p = p->link;
	}
	printf("The number of nodes are %d\n",n );
}// end of Countnode function !!!

void search(struct node *start, int x)
{
	struct node *p;
	int position = 1;
	p = start;
	while(p != NULL)
	{
		if(p -> info == x)
			break;
		position++;
		p = p-> link;

	}
	if (p == NULL)
		printf("%d Not found in list",x);
	else
		printf("%d is at position %d\n",x,position);
}//End for the search function

void insertAfter(struct node *start, int data , int x)
{
	struct node *temp, *p;

	p = start;
	while(p != NULL)
	{
		if(p-> info == x)
			break;
		p = p -> link;
	}
	if( p == NULL)
		printf("%d is not present in the list\n",x);
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> info = data;
		temp -> link = p -> link;
		p -> link = temp;
	}
}
struct node *insertBefore(struct node *start, int data, int x)
{
	struct node *temp,*p;

	//if list is empty 
	if(start== NULL)
	{
		printf("List is empty\n");
		return start;
	}
	// x is the first node, new node is to be inserted before the first node
	if (x == start-> info){
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> info = data;
		temp ->link = start;
		start = temp;
		return start;
	}
	//find pointer of the predecessor of node containing x
	p = start;
	while(p->link != NULL)
	{
		if(p->link->info == x)
			break;
		p = p->link;
	}

	if(p->link == NULL)
		printf("%d is not present in the list\n",x );
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> info = data;
		temp -> link = p->link;
		p -> link = temp;
	}
	return start;
}//end of function

struct node * insertAtPosition(struct node *start, int data, int k)
{
	struct node *temp,*p;
	int i;
	if(k ==1)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> info = data;
		temp -> link = start;
		start = temp;
		return start;
	}

	p = start;
	for(i = 1; i<k-1;i++)
		p = p->link;

	if (p == NULL)
		printf("You can only insert upto %dth position\n",i );

	else{
		temp= (struct node *)malloc(sizeof(struct node));
		temp ->info = data;
		temp -> link = p -> link;
		p -> link = temp;
	}
	return start;

}
struct node *deleteNode(struct node *start, int x)
{
	struct node *temp,*p;
	if(start == NULL){
		printf("List is Empty\n");
		return start;
	}
	// deletion of first node
	if(start->info == x)
	{
		temp = start;
		start = start -> link;
		free(temp);
		return start;
	}
	//deletion in middle somewhere
	p = start;
	while(p -> link != NULL){
		if(p ->link-> info == x)
			break;
		p = p -> link;
	}
	if(p -> link == NULL)
		printf("Element %d doesnot Exists\n",x );
	else
	{
		temp = p -> link;
		p -> link= temp -> link;
		free(temp);
	}
	return start;
}

struct node *reverseList(struct node *start)
{
	struct node *prev,*ptr,*next;
	prev = NULL;
	ptr = start;
	while(ptr != NULL)
	{
		next = ptr ->link;
		ptr -> link = prev;
		prev = ptr;
		ptr = next;

	}
	start = prev;
	return start;
}//end of the function
























