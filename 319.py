import math

class Solution:
    def divisions(x:int)->int:
        if x==1:
            return 1
        div=2
        t=int(math.sqrt(x))
        for k in range(2,t+1,1):
            if x%k==0:
                div+=2
        if t*t==x:
            div-=1
        return div  
    def bulbSwitch(self, n: int) -> int:
        dp_array=[1 for i in range(n+1)]
        for i in range(1,n+1,1):
            if Solution.divisions(i)%2!=0:
                dp_array[i]=dp_array[i-1]+1
            else:
                dp_array[i]=dp_array[i-1]
        return dp_array[n]
print(Solution.divisions(1))