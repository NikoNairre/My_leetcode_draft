class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        if len(nums)<3:
            return []
        if len(nums)==3:
            if nums[0]+nums[1]+nums[2]==0:
                return [nums]
            else:
                return []
        nums.sort()
        res=[]
        for first in range(0,len(nums)-2,1):
            l_point=first+1;r_point=len(nums)-1
            while l_point<r_point:
                if nums[first]+nums[l_point]+nums[r_point]==0:
                    k=[nums[first],nums[l_point],nums[r_point]]
                    if not (k in res):
                        res.append(k)
                    l_point+=1
                elif nums[first]+nums[l_point]+nums[r_point]<0:
                    l_point+=1
                elif nums[first]+nums[l_point]+nums[r_point]>0:
                    r_point-=1
        return res