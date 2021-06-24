#include "TheHeaderFile.h"
#include "Graph.h"

void FilltheAdjMatrix(int *matrix)
{
	for (int i = 0; i < mx; i++)
	{
		for (int j =0; j < mx; j++)
		{
			if (i == j)
			*((matrix + i * mx) + j) = 0;
			else
			*((matrix + i * mx) + j) = i * j;
		}
	}
	
}
void printthematrix(int* matrix)
{
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < mx; j++)
		{
			cout << *((matrix + i * mx) + j)<< " ";
		}
		print(" ");
	}

	
}
void printTheGraph(int matrix[mx][mx]) 
{
	int fetvalue = 0;
	 int totaledges = 0;
	for (int vertex = 0; vertex < mx; vertex++) 
	{
		for (int i = 0; i < mx; i++)
		{
			fetvalue = matrix[vertex][i];
			//now make the vertices.
			cout << "Total Edges between vertex " << vertex << "and " << i << "are " << fetvalue << endl;
			if (fetvalue > 0)
			{
				for (int k = 0; k < fetvalue; k++) {
					totaledges++;
					cout << vertex << "-------->" << i << endl;
				}
					fetvalue = 0;
			}
			print(" ");
		}
	}
	print(totaledges)
}

int main()
{
	//First we need a graph actually. 
	//Either in the form of Adjaceny Matrix or Adjacency List

	//Adjacancy Matix.

	int AdjMatrix[mx][mx];
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < mx; j++)
		{
			AdjMatrix[i][j] = 0;
		}
	}
	FilltheAdjMatrix((int *)AdjMatrix);
	printthematrix((int*)AdjMatrix);
	printTheGraph(AdjMatrix);

	
	
	
}