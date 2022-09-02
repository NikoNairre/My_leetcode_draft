class Solution:
    def findAndReplacePattern(self, words: list[str], pattern: str) -> list[str]:        
        res=[]
        for pick_word in words:
            mapping_letter={}
            for i in range(len(pattern)):                           
                if pattern[i] not in mapping_letter:
                    if (pattern[i] not in mapping_letter.keys())and (pick_word[i] in mapping_letter.values()):
                        break
                    mapping_letter[pattern[i]]=pick_word[i]
                else:
                    if mapping_letter[pattern[i]]!=pick_word[i]:
                        break
                if i==len(pattern)-1:
                    res.append(pick_word)
        return res
ws=["abc","deq","mee","aqq","dkd","ccc"]
p="abb"
l1=["a","b","c"]
t="a"
a=Solution()
print(a.findAndReplacePattern(l1,t))