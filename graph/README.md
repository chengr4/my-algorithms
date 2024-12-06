# Graph

## To Data Structure

[My Data Structure - Graph](https://github.com/chengr4/my-data-structures/tree/main/graph)

## Shortest Path



## Dijkstra's Algorithm

- Edsger W. Dijkstra 1959
- Edge 沒有負值時使用
- Greedy
- BFS + min heap
- 用 min heap 儲存每個點到起點的最小距離 `d`

Eg.

| Current vertex | Shortest distance from start vertex | Previous vertex |
| -------------- | ----------------------------------- | --------------- |
| A              | 0                                   ||
| B              | 2                                   | C               |

## Breadth First Search (BFS)

- Shortest path without weight

JavaScript:

```javascript
const visited = new Set();
// need lib or implementation
const queue = new Queue();
const direction = [[0, 1], [0, -1], [1, 0], [-1, 0]];

while (!queue.isEmpty()) {
  const [currRow, currCol] = queue.dequeue();

  for (const [moveRow, moveCol] of direction) {
    const newRow = currRow + moveRow;
    const newCol = currCol + moveCol;
    if(
      newRow >= 0 && newRow < ROWS &&
      newCol >= 0 && newCol < COLS &&
      !visited.has(`${newRow},${newCol}`) &&
      other conditions
    ) {
      visited.add(`${newRow},${newCol}`);
      queue.enqueue([newRow, newCol]);
    }
  }
}
```

C:

```c
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
```

## Union Find

