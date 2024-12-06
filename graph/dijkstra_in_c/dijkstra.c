/*
 * In this file, you'll implement Dijkstra's algorithm to find the least
 * expensive paths in the graph defined in `airports.dat`.  Don't forget to
 * include your name and @oregonstate.edu email address below.
 *
 * Name: Feng-Shih Cheng
 * Email: chengf@oregonstate.edu
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "pq.h"

#define DATA_FILE "airports.dat"

struct node {
    int vertex;
    struct node* next;
    int weight_from_prev;
};

struct graph {
   int num_vertices;
   struct node** adj_list; // list of adjacent vertices for each vertex

};

struct node* create_node(int v, int weight_from_prev) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->weight_from_prev = weight_from_prev;
    new_node->next = NULL;
    return new_node;
}

// n: number of vertices in the graph
struct graph* init_graph(int n) {
    struct graph* graph = malloc(sizeof(struct graph));
    graph->num_vertices = n;
    graph->adj_list = malloc(n * sizeof(struct node*));

    for (int i = 0; i < n; i++) {
        graph->adj_list[i] = NULL; // Initialize each element to NULL
    }
    return graph;
}

void build_adj_list(struct graph* graph, int current_node, int neighbor_node, int weight_to_add) {
    struct node* new_node = create_node(neighbor_node, weight_to_add);
    new_node->next = graph->adj_list[current_node];
    // move neighbor_node to the top of the adj_list
    graph->adj_list[current_node] = new_node;
}

void free_graph(struct graph* g) {
     for (int i = 0; i < g->num_vertices; i++) {
        struct node* current = g->adj_list[i];
        while (current != NULL) {
            struct node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(g->adj_list);
    free(g);    
}

void print_path(int* prev_node_array, int start_node, int current_node) {
    if (current_node == start_node) {
        printf("%d", start_node);
        return;
    }
    print_path(prev_node_array, start_node, prev_node_array[current_node]);
    printf(" -> %d", current_node);
}

int main(int argc, char const *argv[]) {
    /*
     * Open file and read the first two int: num of nodes, num of edges
     */
    int n_nodes, n_edges;
    FILE* file = fopen(DATA_FILE, "r");
    fscanf(file, " %d %d ", &n_nodes, &n_edges);

    struct graph* g = init_graph(n_nodes);
    int n_source, n_destination, weight;

    // Read the file and Build the adjancecy list
    for (int i = 0;i< n_edges;i++) {
        fscanf(file, "%d %d %d", &n_source, &n_destination, &weight);
        build_adj_list(g, n_source, n_destination, weight);
    }

    int* prev_node_array = malloc(n_nodes * sizeof(int));
    int* distance_to_start_array = malloc(n_nodes * sizeof(int));
    
    int start_node;
    printf("Enter the starting node: ");
    scanf("%d", &start_node);
    
    struct pq* min_heap = pq_create();

    // init distance_to_start_array
    for (int i = 0; i < n_nodes; i++) {
        distance_to_start_array[i] = (i == start_node) ? 0 : INT_MAX;
    }

    pq_insert(min_heap, &start_node, 0);

    while(pq_isempty(min_heap) == 0) {
        int current_vertex = *(int*)pq_remove_first(min_heap);
	struct node* neighbor = g->adj_list[current_vertex];

	// traverse the adjacency list
	while(neighbor != NULL) {
	   int alt_distance = distance_to_start_array[current_vertex] + neighbor->weight_from_prev;
	   // update arrays, if we found a shorter path
	   if (alt_distance < distance_to_start_array[neighbor->vertex]) {
  	       distance_to_start_array[neighbor->vertex] = alt_distance;
	       prev_node_array[neighbor->vertex] = current_vertex;
	       pq_insert(min_heap, &neighbor->vertex, alt_distance);
	   }

	   neighbor = neighbor->next;
	}
    }

    // Print the least-cost paths
    for (int i = 0; i < n_nodes; i++) {
        if (distance_to_start_array[i] == INT_MAX) {
            printf("No flights available to city %d\n", i);
        } else {
            printf("Distance from node %d to node %d is %d\n", start_node, i, distance_to_start_array[i]);
            printf("Path: ");
            print_path(prev_node_array, start_node, i);
            printf("\n");
        }
    }

    free_graph(g);
    pq_free(min_heap);
    free(prev_node_array);
    free(distance_to_start_array);
    fclose(file);
    
    return 0;
}
