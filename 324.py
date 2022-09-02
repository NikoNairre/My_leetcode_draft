class Solution:
    def wiggleSort(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        mid=0
        if len(nums)%2==0:
            mid=len(nums)//2
        else:
            mid=len(nums)//2+1        
        op_list=nums
        op_list.sort()
        smalls=op_list[:mid]
        bigs=op_list[mid:]
        for i in range(0,len(nums),2):
            nums[i]=smalls[i//2]
            if i+1<len(nums):
                nums[i+1]=bigs[i//2] 
a=Solution()
a.wiggleSort([1,5,1,1,6,4])
        