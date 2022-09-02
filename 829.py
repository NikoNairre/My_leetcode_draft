from itertools import count
from math import *
class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        if n==1:
            return 1
        count=2
        if n%2==1:
            lim=int(sqrt(n))
            for i in range(2,lim+1):
                if n%i==0:
                    count+=1
                    if (n//i)!=i:
                        count+=1
            return count
        else:
            n=n//2
            return self.consecutiveNumbersSum(n)
a=Solution()
for i in range(1,101):
    print(a.consecutiveNumbersSum(i),end=" ")