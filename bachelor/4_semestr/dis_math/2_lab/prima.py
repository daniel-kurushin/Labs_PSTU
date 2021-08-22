# Реализация Python3, чтобы найти минимум
# связующее дерево для представления смежности.

from sys import maxsize
from graphviz import Source
INT_MAX = maxsize

#V = 5

def truedge(u, v, arr):
    if u == v:
        return False
    if arr[u] == False and arr[v] == False:
        return False
    elif arr[u] == True and arr[v] == True:
        return False
    return True

def prima(in_graph):
    arr = [False] * len(in_graph)
    arr[0] = True
    edge_count = 0
    while edge_count < len(in_graph) - 1:
        minn = INT_MAX
        a = -1
        b = -1
        for i in range(len(in_graph)):
            for j in range(len(in_graph)):
                if in_graph[i][j] < minn:
                    if truedge(i, j, arr):
                        minn = in_graph[i][j]
                        a = i
                        b = j  
        if a != -1 and b != -1:
            print("Ребро %d: (%d, %d) вес: %d" % (edge_count, a, b, minn))
            edge_count += 1
            arr[b] = arr[a] = True  
    

in_graph = [[INT_MAX, 2, INT_MAX, 6, INT_MAX], 
        [2, INT_MAX, 3, 8, 5],
        [INT_MAX, 3, INT_MAX, INT_MAX, 7], 
        [6, 8, INT_MAX, INT_MAX, 9],
        [INT_MAX, 5, 7, 9, INT_MAX]]
prima(in_graph)
counter = 0
for i in range(len(in_graph)):
    for j in range(counter):
        in_graph[i][j] = INT_MAX
    counter = counter + 1
temp= "graph G {"
for i in range(len(in_graph)):
    for j in range(len(in_graph)):
        if in_graph[i][j] != INT_MAX:
            temp += " %s -- %s [label=\"%s\"] " % (i, j, in_graph[i][j])
temp += "}"
s = Source(temp, filename="graph.gv", format="png")
s.view()