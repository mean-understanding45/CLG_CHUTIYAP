
class Graph:
    graph = {}
    def __init__(self):
        pass

    def addVertices(self):
        n = int(input("Enter number of vertices: "))
        for i in range(n):
            vname = int(input("Enter name of vertex: "))
            adj = set(map(int,input("Enter space separated adjacent vertices: ").split()))
            self.graph[vname] = adj

    def dfs(self,start):
        visited = set()
        visited.add(start)
        l = []
        l.append(start)
        while len(l)>0:
            x = l.pop()
            visited.add(x)
            print(x, end=" ")
            l += list(self.graph[x] - visited)
            # print(l)
        print()


    def bfs(self,start):
        visited = set()
        q = collections.deque()
        q.append(start)
        visited.add(start)

        while q:
            vertex = q.popleft()
            print(vertex,end=" ")
            for neighbour in self.graph[vertex]:
                if neighbour not in visited:
                    visited.add(neighbour)
                    q.append(neighbour)
        print()
g = Graph()
g.addVertices()
while True:
    print("****************MENU*****************")
    print("1. DFS")
    print("2. BFS")
    print("3. Change Graph")
    print("0. Exit")
    print("*************************************")
    choice = int(input("Enter your choice: "))
    if choice == 0:
        exit(0)
    elif choice == 1:
        s = int(input("Enter starting vertex: "))
        g.dfs(s,None)
    elif choice == 2:
        s = int(input("Enter starting vertex: "))
        g.bfs(s,None)
    elif choice == 3:
        g.addVertices()
    else:
        print("Enter valid input!")
