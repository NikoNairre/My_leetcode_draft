class Solution:
    def sum_digits(test:int) -> int:
        tt=str(test)
        result=0
        for i in range(len(tt)):
            result+=int(tt[i])
        return result
    def addDigits(self, num: int) -> int:
        if num<10:
            return num
        return Solution.addDigits(self,Solution.sum_digits(num))
a=Solution()
print(a.addDigits(123456789))