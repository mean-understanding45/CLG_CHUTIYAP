class node:
    def __init__(self,label) -> None:
        self.label = label
        self.visited = False


class Queue:
    def __init__(self) -> None:
        self.queue = [-1] * 100
        self.front = 0
        self.rear = -1
    def insert(self,element):
        self.rear += 1
        self.queue[self.rear] = element
    def remove(self):
        self.front += 1
        return self.queue[self.front - 1]
    def isEmpty(self):
        if self.front > self.rear:
            return True
        return False
class graph:
    def __init__(self) -> None:
        self.numNodes = int(input("Enter number of vertices:"))
        self.adjacencyMatrix = [[-1]*self.numNodes for i in range(self.numNodes)]
        self.nodes = [node(i) for i in range(1,self.numNodes+1)]
    
    def addEdge(self,start,end):
        self.adjacencyMatrix[start - 1][end - 1] = 1
        self.adjacencyMatrix[end - 1][start - 1] = 1
    
    def getUnvisitedVertex(self,start):
        for index,node in enumerate(self.nodes):
            if self.adjacencyMatrix[start - 1][index] == 1 and node.visited == False:
                return node.label
        return -1
    
    def edgeList(self):
        print("Edge List:")
        for node in range(len(self.adjacencyMatrix)):
            print(f"{node + 1}-> ",end="")
            for i,val in enumerate(self.adjacencyMatrix[node]):
                if val == 1:
                    print(i + 1,end=" ")
            print()
    
    def recursiveDFS(self,node,element=None):
        found = False
        self.nodes[node - 1].visited = True
        if node == element:
            found = True
        print(node,end=" ")
        unvisitedVertex = self.getUnvisitedVertex(node)
        while unvisitedVertex != -1:
            self.nodes[unvisitedVertex - 1].visited = True
            result = self.recursiveDFS(unvisitedVertex,element)
            if result == True:
                found = True
            unvisitedVertex = self.getUnvisitedVertex(node)
        return found

    def depthFirstSearch(self):
        print("Depth First Search:")
        start = int(input("Enter the node to perform search from:"))
        self.recursiveDFS(start)
        print()
        for node in self.nodes:
            node.visited = False
    
    def recursiveBFS(self,queue:Queue):
        if queue.isEmpty() == True:
            return
        current = queue.remove()
        unvisitedVertex = self.getUnvisitedVertex(current)
        while unvisitedVertex != -1:
            self.nodes[unvisitedVertex - 1].visited = True
            print(unvisitedVertex,end=" ")
            queue.insert(unvisitedVertex)
            unvisitedVertex = self.getUnvisitedVertex(current)
        self.recursiveBFS(queue)

    def breadthFirstSearch(self):
        print("Breadth First Search")
        start = int(input("Enter the node to perform search from:"))
        queue = Queue()
        queue.insert(start)
        self.nodes[start - 1].visited = True
        print(start,end=" ")
        self.recursiveBFS(queue)
        print()
        for node in self.nodes:
            node.visited = False
    
    def searchElement(self):
        element = int(input("Search element: "))
        start = 1
        print("Searching: ",end="")
        found = self.recursiveDFS(start,element)
        print()
        for node in self.nodes:
            node.visited = False
        if found == True:
            print("Vertex Found")
        else:
            print("Vertex Not Found")


#Input Graph
# 
#         1
#        /|\
#       / | \
#      /  |  \
#     2   3   4
#     \   |   /
#      \  |  /
#       \ | /
#         5
# 


g = graph()
g.addEdge(1,2)
g.addEdge(1,3)
g.addEdge(1,4)
g.addEdge(5,2)
g.addEdge(5,3)
g.addEdge(5,4)
g.edgeList()
g.depthFirstSearch()
g.breadthFirstSearch()
g.searchElement()