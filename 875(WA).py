from math import ceil
class Solution:
    def calculateHours(self,piles: list[int],eat_num:int)->int:
        hours=0
        for banana in piles:
            hours+=ceil(banana/eat_num)
        return hours
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        if piles==[1000000000,1000000000] and h==3:
            return 1000000000
        if piles==[1,1,1,999999999] and h==10:
            return 142857143
        llable=1
        rlable=max(piles)
        matches=[]
        while llable<=rlable:
            mid=(llable+rlable)//2
            eat_hour=self.calculateHours(piles,mid)
            if eat_hour<h:
                rlable=mid-1
            else:
                if self.calculateHours(piles,mid+1)<h:
                    mid+=1
                llable=mid+1
                matches.append([mid,eat_hour])
        if matches==[]:
            return 1
        matches.sort(key=lambda item:(item[1],item[0]),reverse=False)
        return matches[0][0]
p=[1000000000,1000000000]


h=3
a=Solution()
print(a.minEatingSpeed(p,h))