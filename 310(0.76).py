class Solution:
    def dfs(g:list[list[int]],st:int,visit:list[int],step:int,res:list[int]):
        visit[st]=1
        for next in g[st]:
            if visit[next]==0:
                Solution.dfs(g,next,visit,step+1,res)
        visit[st]=0
        res.append(step)
        return max(res)
    def findMinHeightTrees(self, n: int, edges: list[list[int]]) -> list[int]:
        graph=[[] for i in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        vis=[0 for i in range(n)]
        ans=[]
        for i in range(n):
            ans.append(Solution.dfs(graph,i,vis,0,[]))
        r=[]
        m=min(ans)
        for i in range(len(ans)):
            if ans[i]==m:
                r.append(i)
        return r
a=Solution()
x=4
e=[[1,0],[1,2],[1,3]]
print(a.findMinHeightTrees(x,e))
