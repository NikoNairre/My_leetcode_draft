from turtle import left, right
from unittest import result
class Solution:
    def platesBetweenCandles(self, s: str, queries: list[list[int]]) -> list[int]:
        n=len(s)
        m=len(queries)
        result=[0]*m
        prem_sum=[0]*n
        left_cpos=[0]*n
        right_cpos=[0]*n
        num_plants=0;l=-1;r=-1
        for i,it in enumerate(s):
            if it=="*":
                num_plants+=1
            else:
                l=i
            prem_sum[i]=num_plants
            left_cpos[i]=l
        for i in range(n-1,-1,-1):
            if s[i]=="|":
                r=i
            right_cpos[i]=r
        for i in range(len(queries)):
            start=queries[i][0]
            end=queries[i][1]
            x=right_cpos[start]
            y=left_cpos[end]
            if x>=0 and y>=0 and x<y:
                result[i]=prem_sum[y]-prem_sum[x]
        return result
s='***|**|*****|**||**|*'
b=[[1,17],[4,5],[14,17],[5,11],[15,16]]
for i,item in enumerate(b):
    print(i)
    print(item)
a=Solution()
g=a.platesBetweenCandles(s,b)
print(g)
        