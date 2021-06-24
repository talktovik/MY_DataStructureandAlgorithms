#pragma once
#include <iostream>
#include<vector>
#define  mx 8
using namespace std;
class Graph
{
	int Vertex;
	int Edges;
	int** AdjancyMatrix;
public:
	Graph(int Vertex, int Edges);
	void addEdge(int start, int end);
	void BFS(int start);
	void BFS(int matrix[mx][mx]);
};

