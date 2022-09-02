class Solution:
    def find_longest(self,answerKey: str, k: int,aim:str):
        if len(answerKey)==1:
            return 1
        l_point=0;r_point=0
        difference=0
        max_len=0
        while r_point<len(answerKey):
            if answerKey[r_point]!=aim:
                difference+=1
                if difference==k:
                    cur_len=r_point-l_point+1
                    max_len=max(cur_len,max_len)
                elif difference>k:
                    while difference>k:
                        if answerKey[l_point]!=aim:
                            difference-=1
                        l_point+=1
                    cur_len=r_point-l_point+1
                    max_len=max(cur_len,max_len)
                r_point+=1
            else:
                cur_len=r_point-l_point+1
                max_len=max(cur_len,max_len)
                r_point+=1
        return max_len
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        a=Solution.find_longest(self,answerKey,k,"T")
        b=Solution.find_longest(self,answerKey,k,"F")
        return max(a,b)
s=input()
k=int(input())
l=Solution()
print(l.maxConsecutiveAnswers(s,k))
