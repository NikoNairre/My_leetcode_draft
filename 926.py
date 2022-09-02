class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n=len(s)
        dp=[0 for i in range(n)]
        for i in range(1,n):
            pre=s[:i]
            cu=dp[i-1]
            if s[i]=="1":
                pass
            else:
                cu=dp[i-1]+1
            dp[i]=min(cu,pre.count("1"))
        return dp[n-1]
s="010110"
a=Solution()
print(a.minFlipsMonoIncr(s))