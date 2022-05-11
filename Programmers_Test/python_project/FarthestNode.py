def solution(n, edge):
    answer = 0
    graph = [[] for i in range(n+1)]
    visited = [0]*(n+1)
    visited[1] = 1
    farnodes = [1]
    for x,y in edge:
        graph[x].append(y)
        graph[y].append(x)
    while farnodes:
        nodes = len(farnodes)
        for i in range(nodes):
            current = farnodes.pop(0)
            for c in graph[current]:
                if not visited[c]:
                    visited[c] = visited[current]+1
                    farnodes.append(c)
    return nodes
