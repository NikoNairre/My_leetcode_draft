arr=[int(i) for i in input().split()]
class Solution:
    def canReorderDoubled(self, arr: list[int]) -> bool:
        pool={}
        arr.sort()
        for num in arr:
            if num not in pool:
                pool[num]=1
            else:
                pool[num]+=1
        can=True
        if arr.count(0)%2!=0:
            return False
        if 0 in pool:
            pool.pop(0)
        for num in arr:
            if num!=0 and (num in pool) and (num*2 in pool):
                pool[num]-=1
                pool[num*2]-=1
                if pool[num]==0:
                    pool.pop(num)
                if pool[num*2]==0:
                    pool.pop(num*2)
        if len(pool)==0:
            can=True
        else:
            can=False
        return can
s=Solution()
print(s.canReorderDoubled(arr))