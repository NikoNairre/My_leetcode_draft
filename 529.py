vs=[[0]*5 for i in range(5)]
vs[1][2]=2
print(vs)
class Solution:
    sourrounds=[[0,1],[1,1],[1,0],[1,-1],[0,-1],[-1,-1],[-1,0],[-1,1]]
    def dfs(self, board: list[list[str]],aimx:int,aimy:int):
        m=len(board);n=len(board[0])
        mines=0
        for next in Solution.sourrounds:
            ex=aimx+next[0];ey=aimy+next[1]
            if ex<0 or ex>=m or ey<0 or ey>=n:
                continue
            if board[ex][ey]=="M":
                mines+=1
        if mines>0:
            board[aimx][aimy]=str(mines)
        else:
            board[aimx][aimy]="B"
            for next_s in Solution.sourrounds:
                nx=aimx+next_s[0];ny=aimy+next_s[1]
                if nx<0 or nx>=m or ny<0 or ny>=n or board[nx][ny]!="E":
                    continue
                Solution.dfs(self,board,nx,ny)
    def updateBoard(self, board: list[list[str]], click: list[int]) -> list[list[str]]:
        l=len(board);col=len(board[0])
        x=click[0];y=click[1]
        if board[x][y]=="M":
            board[x][y]="X"
        else:
            Solution.dfs(self,board,x,y)

        return board
k=Solution()
s=[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
c=[3,0]
print(k.updateBoard(s,c))
