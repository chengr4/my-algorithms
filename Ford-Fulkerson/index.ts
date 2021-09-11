const graph: number[][] = [
  [0, 16, 13, 0, 0, 0],
  [0, 0, 10, 12, 0, 0],
  [0, 4, 0, 0, 14, 0],
  [0, 0, 9, 0, 0, 20],
  [0, 0, 0, 7, 0, 4],
  [0, 0, 0, 0, 0, 0],
];

function fordFulkerson(graph: number[][], source: number, sink: number) {
  if (sink < 0 || sink < 0 || source > graph.length-1 || sink > graph.length-1){
    throw new Error("Invalid sink or source");
  }
  if(graph.length === 0){
    throw new Error("Invalid graph");
  }
}
