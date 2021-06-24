#include "Graph.h"
#define mx 8



#define AM AdjancyMatrix
Graph::Graph(int Vertex, int Edges) 
{
	this->Vertex = Vertex;
	this->Edges = Edges;

	//Here we are creating our own Adjacancy Matrix.
	AdjancyMatrix = new int* [Vertex];
	for (int row = 0; row < Vertex; row++) 
	{
		AdjancyMatrix[row] = new int[Vertex];
		for (int column = 0; column < Vertex; column++)
			AdjancyMatrix[row][column] = 0;
	}
}

void Graph::addEdge(int start, int end) 
{
	//doing this because the graph is undirected.
	AM[start][end] = 1;
	AM[end][start] = 1;
	
}

void Graph::BFS(int start)
{
	
	bool* Visited = (bool *)malloc(sizeof(bool) * Vertex);
	for (int i = 0; i < Vertex; i++)
		Visited[i] = false;
	vector<int> Queue;
	Queue.push_back(start);
	Visited[start] = true;

	int variable;
	while (!Queue.empty())
	{
		variable = Queue[0];

		//Printing the current node
		cout << variable << " ";
		Queue.erase(Queue.begin());
		
		for (int i = 0; i < Vertex; i++)
		{
			if (AM[variable][i] == 1 && (!Visited[i])) 
			{
				// Push the adjacent node to the Queue.
				Queue.push_back(i);
				Visited[i] = true;

			}
		}
	}
}

//for the adjacency matrix which we created so that we can use that.
void Graph::BFS(int matrix[mx][mx])
{
	int start = 1;
	Vertex = mx;
	cout << " " << endl;


	bool* Visited = (bool*)malloc(sizeof(bool) * Vertex);
	for (int i = 0; i < Vertex; i++)
		Visited[i] = false;
	vector<int> Queue;
	Queue.push_back(start);
	Visited[start] = true;

	int variable;
	while (!Queue.empty())
	{
		variable = Queue[0];

		//Printing the current node
		cout << variable << " ";
		Queue.erase(Queue.begin());

		for (int i = 0; i < Vertex; i++)
		{
			if (matrix[variable][i] == 1 && (!Visited[i]))
			{
				// Push the adjacent node to the Queue.
				Queue.push_back(i);
				Visited[i] = true;

			}
		}
	}
}