# To represtn graph
graph = {}

# make undirected graph
# i.e. edge from startNode to endNode
# and endNode to startNode
def make_simple_graph(startNode, endNode):
    # if startNode is already present in graph
    # then push endNode in the list of startNode
    if startNode in graph:
        graph[startNode].append(endNode)
    # if endNode in graph
    # then push startNode into the list of endNode
    if endNode in graph:
        graph[endNode].append(startNode)
    # if startNode is not present into the graph
    # then create adjacecny list
    # and push end node in that list
    if startNode not in graph:
        graph[startNode] = []
        graph[startNode].append(endNode)
    # if endNode is not present into the graph
    # then create adjacecny list
    # and push start node in that list
    if endNode not in graph:
        graph[endNode] = []
        graph[endNode].append(startNode)


# Make edges between these vertices
make_simple_graph('B', 'D')
make_simple_graph('D', 'E')
make_simple_graph('D', 'A')
make_simple_graph('E', 'C')
make_simple_graph('E', 'A')
make_simple_graph('A', 'C')

# Print graph
for key, value in graph.items():
    # Parent Node
    print(key+"->", end="")
    # Print neighbour nodes
    for ele in value:
        print(ele, end=" ")
    print()
