import heapq

def prims(graph, start):
    visited = set()
    mst = []
    min_heap = [(0, start, None)]
    total_cost = 0

    while min_heap:
        weight, node, parent = heapq.heappop(min_heap)

        if node in visited:
            continue

        visited.add(node)

        if parent is not None:
            mst.append((parent, node, weight))
            total_cost += weight

        for neighbor, edge_weight in graph[node]:
            if neighbor not in visited:
                heapq.heappush(
                    min_heap,
                    (edge_weight, neighbor, node)
                )

    if len(visited) != len(graph):
        print("Graph is disconnected!")
        return

    print("Minimum Spanning Tree:")
    for u, v, w in mst:
        print(f"{u} - {v} : {w}")

    print("Total cost:", total_cost)


# Graph represented as an adjacency list
graph = {
    'A': [('B', 2), ('C', 3)],
    'B': [('A', 2), ('C', 1), ('D', 4)],
    'C': [('A', 3), ('B', 1), ('D', 5)],
    'D': [('B', 4), ('C', 5)]
}

prims(graph, 'A')
