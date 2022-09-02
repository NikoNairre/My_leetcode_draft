class Solution:
    def makesquare(self, matchsticks: list[int]) -> bool:
        all_length=sum(matchsticks)
        if all_length%4!=0:
            return False
        edge_length=all_length//4
        matchsticks.sort(reverse=True)
        edge=[0,0,0,0]
        def dfs(x:int)->bool:
            if x==len(matchsticks):
                return True
            for i in range(4):
                edge[i]+=matchsticks[x]
                if edge[i]>edge_length:
                    return False                
                dfs(x+1)
                return True
                edge[i]-=matchsticks[x]
            return False
        return dfs(0)
m=[1,1,2,2,2]
a=Solution()
print(a.makesquare(m)) 