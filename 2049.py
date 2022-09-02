class Solution:
    def countHighestScoreNodes(self, parents: list[int]) -> int:
        n=len(parents)
        tree_graph=[[] for item in range(n)]
        for i,mum in enumerate(parents):
            if mum!=-1:
                tree_graph[mum].append(i)
        max_score=0
        count=0
        def dfs(node:int):
            score=1
            num_vers=n-1
            for child in tree_graph[node]:
                next_cht_num=dfs(child)
                score*=next_cht_num
                num_vers-=next_cht_num
            if node!=None:
                score*=num_vers
           # nonlocal max_score, count
            if score==max_score:
                count+=1
            elif score>max_score:
                max_score=score
                count=1
            return n-num_vers
        dfs(0)
        return count
s=[int(n) for n in input().split(',')]
print(s)
a=Solution()
print(a.countHighestScoreNodes(s))