class Solution:
    def get_count(self,x:int,n:int)->int:
        st=x
        finish=x+1
        num=0
        while st<=n:
            num+=min(n+1,finish)-st
            st*=10
            finish*=10
        return num
    def findKthNumber(self, n: int, k: int) -> int:
        prexindex=1
        p=1
        while p<k:
            cur_p=Solution.get_count(self,prexindex,n)
            if p+cur_p>k:
                prexindex*=10
                p+=1
            else:
                prexindex+=1
                p+=cur_p
        return p