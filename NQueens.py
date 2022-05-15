class NQueens:
    def __init__(self):
        self.n=8
        self.val=[0,1,2,3,4,5,6,7]
        self.sol=[0]*(self.n)

    def checkpast(self,index,c):
        if(self.sol):
            for v in range(index):
                if(self.sol[v]==c):
                    return False
                if(self.sol[v]-c==v-index):
                    return False
                if(c-self.sol[v]==v-index):
                    return False


        return True




    def dfs_visited(self,index):
        # Exit condition.
        if(self.n==index):
            return True
        for c in self.val:
            if(self.checkpast(index,c)):
                self.sol[index]=c
                if(self.dfs_visited(index+1)):
                    return True
                else:
                    continue
        #Backtracking.
        self.sol[index]=None
        return False
    def dfs(self):
        self.dfs_visited(0)
b1=NQueens()
b1.dfs()
print("The chess board is",b1.n,"*",b1.n)
print("The configuration of the queens on the chessboard should be",b1.sol)
