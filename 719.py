class Solution:
    def smallestDistancePair(self, nums: list[int], k: int) -> int:
        nums.sort()
        left=0 ; right=nums[-1]-nums[0]
        cur=0
        while left<=right:
            mid=(left+right)//2
            i,j=0,0
            count=0
            while j<len(nums):
                if nums[j]-nums[i]<=mid:
                    count+=j-i    
                    j+=1
                    continue
                
                i+=1
            # while i<j-1:
            #     i+=1
            #     count+=j-1-i
            if count<k:
                left=mid+1
            else:
                right=mid-1
                cur=mid
        return cur
a=[1,3,1]
b=1
s=Solution()
print(s.smallestDistancePair(a,b))