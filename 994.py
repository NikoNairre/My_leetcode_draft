from collections import deque    #使用队列进行广度优先搜索
class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        next_step=[[0,1],[1,0],[0,-1],[-1,0]]  #下一步的四个方向
        length=len(grid); width=len(grid[0])   #记录橘子图的长和宽
        q=deque()
        visit=[[0]*width for i in range(length)]#建立和grid一样大的状态访问数组
        fresh=0                                #记录新鲜橘子的数量
        for i in range(length):
            for j in range(width):
                if grid[i][j]==2:
                    q.append([i,j])            #遇到了腐烂的橘子，加入队列
                    visit[i][j]=1              #腐烂橘子的位置标记为已经走过，避免重复统计
                elif grid[i][j]==1:         
                    fresh+=1                   #遇到新鲜的橘子，fresh递增
        if fresh==0:                           #如果没有新鲜橘子，直接返回结果0（因为第0分钟，图里就已经全是腐烂橘子，或者没有橘子）
            return 0
        second=-1             #我不明白为什么second初始值要设为-1而不是0
        while len(q)>0:       #BFS
            one_minute=len(q)
            for j in range(one_minute):  #该循环实现每一分钟，橘子腐烂状态的变化
                cur=q.popleft()          #从队列取出当前需要处理的位置
                for next in next_step:   #利用方向数组，遍历当前位置四周橘子的情况
                    nx=cur[0]+next[0]
                    ny=cur[1]+next[1]    #nx，ny表示新的位置
                    if nx<0 or nx>=length or ny<0 or ny>=width or grid[nx][ny]==0:
                        continue         #如果越界，或者该处没有橘子，则舍弃该点，重新循环
                    if grid[nx][ny]==1 and visit[nx][ny]==0:#新位置是好橘子，并且没有被访问过
                        grid[nx][ny]=2   #橘子烂了
                        fresh-=1         #新鲜橘子少了1个
                        visit[nx][ny]=1  #防止重复搜索，标记为已经访问
                        q.append([nx,ny])#将该位置入队，便于之后处理该位置邻接位置的情况
            second+=1                    #1分钟的腐烂情况结束，second递增
        return -1 if fresh>0 else second #如果全部搜索结束后依然有好橘子，返回-1，否则，返回橘子全部腐烂经过的分钟数
a=Solution()
print(a.orangesRotting([[2,1,1],[1,1,0],[0,1,1]]))
