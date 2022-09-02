class Solution:
    def makesquare(self, matchsticks: list[int]) -> bool:
        all_length=sum(matchsticks)
        if all_length%4!=0:
            return False
        edge_length=all_length//4
        matchsticks.sort(reverse=True)
        p1,p2,p3,p4=0,0,0,0
        cur=0
        while cur<len(matchsticks) and p1<edge_length:
            p1+=matchsticks[cur]
            if p1>edge_length:
                return False
            cur+=1
        while cur<len(matchsticks) and p2<edge_length:
            p2+=matchsticks[cur]
            if p2>edge_length:
                return False
            cur+=1
        while cur<len(matchsticks) and p3<edge_length:
            p3+=matchsticks[cur]
            if p3>edge_length:
                return False
            cur+=1
        while cur<len(matchsticks) and p4<edge_length:
            p4+=matchsticks[cur]
            if p4>edge_length:
                return False
            cur+=1
        if p1==p2 and p2==p3 and p3==p4:
            return True
        else:
            return False        
m=[3,3,3,3,4]
a=Solution()
print(a.makesquare(m))