/*  Recitation Acitivty 8:
    Write a function to determine if an undirected graph is connected.
	The function connected will return a 1 if the graph is connected and 
	a 0 if not connected.  The graph is represented by a Graph struct that 
	consists of the numVertices, an array of adjacency lists, and a visited 
	array that can be used in your algorthm.  
	
	I have included the queue and dynamic array data structues from previous
	assignments.  However, you do not have to use these and you can include 
	other previously written data structures, or write new ones.
	
	The test case graphs are in the main program.
*/
	

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "dynarray.h"

/* Node for the adjacency list */
struct node {
  int vertex;
  struct node* next;
};


/* Graph struct including Adjacency List  */
struct Graph {
  int numVertices;         // number of vrtices in the graph
  struct node** adjLists;  // list of adjacent vertices for each vertex
  int* visited;            //  1 == vertex has been visited, initialized to 0
};

// function that creates a node for vertex v
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a new graph
struct Graph* createGraph(int n) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = n;     // number of vertices in the graph

  graph->adjLists = malloc(n * sizeof(struct node*));
  graph->visited = malloc(n * sizeof(int)); // visited array

  for (int i = 0; i < n; i++) {
    graph->adjLists[i] = NULL;    // adjacency lists are empty
    graph->visited[i] = 0;        // visited initialized to 0
  }

  return graph;
}

/* Add edges to an exisiting undirected graph
   The edge (u,v) must be added to both u's and v's 
   adjacency lists                                */

void addEdge(struct Graph* graph, int u, int v) {
  // Add edge from u to v
  struct node* newNode = createNode(v);
  newNode->next = graph->adjLists[u];
  graph->adjLists[u] = newNode;

  // Add edge from v to u
  newNode = createNode(u);
  newNode->next = graph->adjLists[v];
  graph->adjLists[v] = newNode;
}


void bfs(struct Graph* graph, int startVertex) {
	struct queue* queue = queue_create();

	graph->visited[startVertex] = 1;
	queue_enqueue(queue, graph->adjLists[0]);

	while (!queue_isempty(queue)) {
		struct node* currentVertex = queue_dequeue(queue);

		struct node* temp = currentVertex;

		while (temp != NULL) {
			int adjVertex = temp->vertex;

			if (graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				
				// Add the adjacent vertex to the queue
				queue_enqueue(queue, graph->adjLists[adjVertex]);
			}
			temp = temp->next;
		}
	}
}

int connected(struct Graph* graph) {
	bfs(graph, 0);

	for (int i = 0; i < graph->numVertices; i++) {
		if (graph->visited[i] == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	/* Do not modify main  */
    // Test Case 1: Graph 1 
	int n = 7;
	
	struct Graph* graph1 = createGraph(n);
	addEdge(graph1, 0, 1);
	addEdge(graph1, 0, 2);
	addEdge(graph1, 1, 2);
	addEdge(graph1, 1, 4);
	addEdge(graph1, 1, 3);
	addEdge(graph1, 2, 4);
	addEdge(graph1, 3, 4);
	addEdge(graph1, 5, 6);
	//int result = connected(graph1);	
	if ( connected(graph1) == 1) 
		printf("Graph 1 is Connected \n");
	else
		printf("Graph 1 is Disconnected \n");	

    // Test Case 2: Graph 2	
	n  = 10;
 	struct Graph* graph2 = createGraph(n);
	for (int i = 0; i < 5; i++) {
		for (int j = i+1; j < 5 ; j++ ) {				
			addEdge(graph2, i, j);
		}
	}
	for (int i = 5; i < n; i++) {
		for (int j = i+1; j < n ; j++ ) {				
			addEdge(graph2, i, j);
		}
	}

	if ( connected(graph2) == 1) 
		printf("Graph 2 is Connected \n");
	else
		printf("Graph 2 is Disconnected \n");		

    // Test Case 3: Graph 3
	n  = 8;
 	struct Graph* graph3 = createGraph(n);
	addEdge(graph3, 0, 1);
	addEdge(graph3, 0, 2);
	addEdge(graph3, 1, 2);
	addEdge(graph3, 1, 3);
	addEdge(graph3, 1, 5);
	addEdge(graph3, 2, 4);
	addEdge(graph3, 4, 6);
	addEdge(graph3, 6, 7);

	if ( connected(graph3) == 1) 
		printf("Graph 3 is Connected \n");
	else
		printf("Graph 3 is Disconnected \n");	

    // Test Case 4: Graph 4
	n  = 10;
 	struct Graph* graph4 = createGraph(n);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n ; j++ ) {				
			addEdge(graph4, i, j);
		}
	}

	if ( connected(graph4) == 1) 
		printf("Graph 4 is Connected \n");
	else
		printf("Graph 4 is Disconnected \n");

    // Test Case 5: Graph 5
	n  = 20;
 	struct Graph* graph5 = createGraph(n);
	for (int i = 0; i < n; i++) {
		for (int j = i+2; j < n ; j+=2 ) {				
			addEdge(graph5, i, j);
		}
	}

	if ( connected(graph5) == 1) 
		printf("Graph 5 is Connected \n");
	else
		printf("Graph 5 is Disconnected \n");			
    return 0;
}