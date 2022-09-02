import queue
class Solution:
    def networkBecomesIdle(self, edges: list[list[int]], patience: list[int]) -> int:
        graph=[[] for i in range(len(patience))]
        for egde in edges:
            graph[egde[0]].append(egde[1])
            graph[egde[1]].append(egde[0])
        op=queue.Queue()
        op.put(0)
        visit=[0 for i in range(len(patience))]
        step=1
        #BFS
        visit[0]=1
        res=0
        while not op.empty():
            for j in range(op.qsize()):
                current_node=op.get()
                for neighbour in graph[current_node]:
                    if visit[neighbour]==1:
                        continue
                    rings=patience[neighbour]
                    max_time=0
                    if rings>=step*2:
                        max_time=step*2+1
                    else:
                        max_time=rings*((step*2-1)//rings)+step*2+1
                    res=max(max_time,res)
                    visit[neighbour]=1
                    op.put(neighbour)
            step+=1            
        return res
e=[[0,1],[0,2],[1,5],[2,3],[2,4],[5,6],[5,3],[3,4],[6,8],[5,8],[5,7],[3,9]]
pa=[0,1,2,3,4,5,6,7,8,9]
c=[[0,1],[1,2]]
d=[0,1,2]
k=[[0,1],[0,2],[1,2]]
f=[0,10,10]
a=Solution()
print(a.networkBecomesIdle(e,pa))