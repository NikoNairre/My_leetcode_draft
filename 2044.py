class Solution:
    def countMaxOrSubsets(self, nums: list[int]) -> int:
        if len(nums)==1:
            return 1
        cases=1<<len(nums)
        answer=0
        max_bit_or=-1
        for i in range(1,cases,1):
            subnums=[]
            for j in range(len(nums)-1,-1,-1):
                t=i&1
                if t==1:
                    subnums.append(nums[j])
                i=i>>1
                if i<=0:
                    break
            bit_or=0
            if len(subnums)==1:
                bit_or=subnums[0]
            else:
                for j in range(0,len(subnums)-1,1):
                    bit_or=subnums[j]|subnums[j+1]
                    subnums[j+1]=bit_or
            if bit_or>max_bit_or:
                max_bit_or=bit_or
                answer=1
            elif bit_or==max_bit_or:
                answer+=1
        return answer
a=5
b=[3,2,1,5]
b.clear()
c=1<<4
d=str(bin(c))[2:]
print(1<<1)