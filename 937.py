class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:
        numbers=[]
        letters=[]
        dic=[]
        for log in logs:
            single=log.split()
            if ord(single[1][0])>=48 and ord(single[1][0])<=57:
                numbers.append(log)
            else:
                content=""
                for i in range(1,len(single),1):
                    if i!=len(single)-1:
                        content=content+single[i]+' '
                    else:
                        content+=single[i]
                dic.append([single[0],content])
        dic.sort(key=lambda item:(item[1],item[0]))
        for logs in dic:
            letters.append(logs[0]+" "+logs[1])
        ans=letters+numbers
        return ans
s=Solution()
print(s.reorderLogFiles(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))

