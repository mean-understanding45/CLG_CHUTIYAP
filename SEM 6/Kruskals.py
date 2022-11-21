class SpanningTree:
    def __init__(self):
        self.numberOfVertices = 0
        self.parent = {}
        self.size = {}
        self.edges = []

    def find(self,root):
        parent = self.parent
        a = root
        while parent[a] != a:
            a = parent[a]
        while root != a:
            nextnode = parent[root]
            parent[root] = a
            root = nextnode
        return a

    def union(self,a, b):
        parent = self.parent
        size = self.size
        a = self.find(a)
        b = self.find(b)
        if a != b:
            if size[a] < size[b]:
                a, b = b, a
            parent[b] = a
            size[a] += size[b]
            return True
        else:
            return False

    def createGraph(self):
        self.parent.clear()
        self.size.clear()
        self.edges = []
        self.numberOfVertices = int(input("\tEnter number of vertices: "))
        numberOfEdges = int(input("\tEnter number of edges: "))
        for edge in range(numberOfEdges):
            node1,node2,weight = map(int,input("\tEnter node1  node2  weight: ").split())
            self.parent[node1] = node1
            self.parent[node2] = node2
            self.size[node1] = 1
            self.size[node2] = 1
            self.edges.append((weight,node1,node2))

    def Kruskals_algo(self):
        self.edges.sort()
        spanningTreeEdges = []
        totalEdges = 0
        for weight,node1,node2 in self.edges:
            if self.union(node1,node2):
                totalEdges+=1
                spanningTreeEdges.append((weight,node1,node2))
            if totalEdges == self.numberOfVertices-1:
                break
        for weight,node1,node2 in spanningTreeEdges:
            print("\t",node1,node2,weight)


if __name__ == '__main__':
    s = SpanningTree()
    while True:
        print("""
        Enter
        1. New graph.
        2. Spanning tree
        3. Exit.""")
        option = int(input("\tEnter choice: "))
        if option == 1:
            s.createGraph()
        elif option == 2:
            s.Kruskals_algo()
        else:
            break
