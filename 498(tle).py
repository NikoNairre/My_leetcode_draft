class Solution:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        m=len(mat) ; n=len(mat[0])
        index_sum=m+n-2
        res=[]
        round=0
        for k in range(index_sum+1):
            for i in range(0,k+1):
                if round%2==0:
                    if (k-i)<0 or (k-i)>=m or i<0 or i>=n:
                        continue
                    res.append(mat[k-i][i])
                else:
                    if i<0 or i>=m or (k-i)<0 or (k-i)>=n:
                        continue
                    res.append(mat[i][k-i])
            round+=1
        return res