# Graph

## To Data Structure

[My Data Structure - Graph](https://github.com/chengr4/my-data-structures/tree/main/graph)

## Dijkstra’s Algorithm

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

## The Shortest Path

```javascript
// js
const visited = new Set();
// need lib or implementation
const queue = new Queue();
const direction = [[0, 1], [0, -1], [1, 0], [-1, 0]];

// BFS
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

## Union Find

