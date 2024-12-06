# Dijkstra

## Instructions

1. Compile the program using the Makefile:

   ```bash
   make
   ```

2. Run the program by executing:

   ```bash
   ./dijkstra
   ```

## Data Structures and Time Complexities

### 1. Graph Representation

- **Structure**: Adjacency List
- **Implementation**: Linked List for each vertex
- **Time Complexity**: O(V + E)
    - V: Number of vertices
    - E: Number of edges

### 2. Priority Queue (Min-Heap)

- Used for efficient selection of minimum distance node
- **Time Complexity**:
  - **Insertion**: O(log V)
  - **Extract Min**: O(log V)

### 3. Dijkstra's Algorithm

- **Time Complexity**: O((V + E) log V)
    - V: Number of vertices
    - E: Number of edges

For each vertex (V):

- it removes O(log V) times
- it explores its edges O(E) times and updates the distances O(log V) times => O(E log V)

So the total becomes:

```
O(V * (log V + E * log V)) => 
O(V log V + V E log V) => 
O((V + E) log V)
```
