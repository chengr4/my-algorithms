from collections import defaultdict

def edge_to_unweight_adjlist(edges):
    adjlist = defaultdict(list)
    # u -> v
    for u ,v in edges:
        adjlist[u].append(v)

    return adjlist

# Time: O(V+E)
def bfs(node_nums, edges):
    adjlist = edge_to_unweight_adjlist(edges)
    # default 0: white
    color = defaultdict(int)
    order = [] # output
    def helper(curr_node):
        queue = [curr_node]
        for u in queue:
            print('curr_u', u)
            order.append(u)
            color[u] = 2 # black
            for w in adjlist[u]: # u -> w
                if color[w] == 0:
                    queue.append(w)
                    color[w] = 1 # gray

    # because the graph might be disconnected or weakly connected
    # or add a hidden dummy node, connecting to all nodes
    for v in range(node_nums):
        if color[v] == 0:
            helper(v)

    return order

def dfs(node_nums, edges):
    adjlist = edge_to_unweight_adjlist(edges)
    # default 0: white
    color = defaultdict(int)
    order = [] # output

    def helper(curr_node):
        color[curr_node] = 1 # gray
        order.append(curr_node)
        for u in adjlist[curr_node]: # curr_node -> u
            if color[u] == 0:
                helper(u)
            elif color[u] == 1: # gray: active; back edge
                # Note there are many other “related” cycles that are not detected in DFS
                print("cycle detected %d->%d" % (v, u)) # this part is optional
        
        color[curr_node] = 2 # black

    for v in range(node_nums):
        if color[v] == 0:
            helper(v)

    return order


if __name__ == "__main__":
    # [0, 6, 2, 4, 3, 5, 1, 7, 8]
    print(bfs(9, [(0,6), (1,6), (6,2), (2,3), (6,4), (4,5), (3,5), (7,3), (7,8)]))
    # [0, 6, 2, 3, 5, 4, 1, 7, 8]
    print(dfs(9, [(0,6), (1,6), (6,2), (2,3), (6,4), (4,5), (3,5), (7,3), (7,8)]))
