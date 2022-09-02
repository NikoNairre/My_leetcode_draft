class Solution:
    def findPairs(self, nums: list[int], k: int) -> int:
        nums.sort()
        if len(nums)==1:
            return 0
        if len(nums)==2:
            if abs(nums[0]-nums[1])==k:
                return 1
            else:
                return 0
        pool=set()
        i,j=0,0
        while j<len(nums):
            if nums[j]-nums[i]<k:
                j+=1
                continue
            if nums[j]-nums[i]==k and j!=i:
                pool.add((nums[i],nums[j]))
            if j<=i:
                j+=1
            else:
                i+=1
        while nums[j-1]-nums[i]<k and j-1>i:
            i+=1
        if nums[j-1]-nums[i]==k and j-1!=i:
            pool.add((nums[i],nums[j]))
        return len(pool)

a=[1, 3, 1, 5, 4]
k=0
s=Solution()
print(s.findPairs(a,k))