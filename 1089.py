class Solution:
    def duplicateZeros(self, arr: list[int]) -> None:
        t=len(arr)
        i=0
        while i<t:
            if arr[i]==0:
                arr.insert(i,0)
                arr.pop()
                i+=2
            else:
                i+=1
        """
        Do not return anything, modify arr in-place instead.
        """