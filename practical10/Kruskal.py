def kruskal(graph, vertices):
    parent = {v: v for v in vertices}

    def find(v):
        if parent[v] != v:
            parent[v] = find(parent[v])
        return parent[v]

    def union(u, v):
        root_u = find(u)
        root_v = find(v)

        if root_u != root_v:
            parent[root_v] = root_u
            return True
        return False

    # Sort edges by weight
    graph.sort(key=lambda x: x[2])

    mst = []
    total_cost = 0

    for u, v, weight in graph:
        if union(u, v):
            mst.append((u, v, weight))
            total_cost += weight

            if len(mst) == len(vertices) - 1:
                break

    print("Edges in Minimum Spanning Tree:")

    for u, v, weight in mst:
        print(u, "-", v, ":", weight)

    print("Total cost:", total_cost)


# Graph: (vertex1, vertex2, weight)
graph = [
    ('A', 'B', 2),
    ('A', 'D', 6),
    ('B', 'C', 3),
    ('B', 'D', 8),
    ('B', 'E', 5),
    ('C', 'E', 7),
    ('D', 'E', 9)
]

vertices = ['A', 'B', 'C', 'D', 'E']

kruskal(graph, vertices)
