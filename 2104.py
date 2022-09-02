class Solution:
    def subArrayRanges(self, nums: list[int]) -> int:
        n=len(nums)
        answer=0
        for i in range(n):
            max_num=-1000000001
            min_num=1000000001
            for j in range(i,n):
                max_num=max(max_num,nums[j])
                min_num=min(min_num,nums[j])
                answer+=max_num-min_num
        return answer
tt=[1,2,3,4,5,6,7,8,90,0]
c=Solution()
print(c.subArrayRanges(tt))
tx=tt[:1]
print(min(tx),end=',')
print(max(tx))