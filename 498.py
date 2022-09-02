class Solution:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        m=len(mat) ; n=len(mat[0])
        index_sum=m+n-2
        res=[]
        for k in range(index_sum+1):
            if k%2==0:
                x=k if k<m else m-1
                y=0 if k<m else k-m+1
                while x>=0 and y<n:
                    res.append(mat[x][y])
                    x-=1
                    y+=1
            else:
                x=0 if k<n else k-n+1
                y=k if k<n else n-1
                while x<m and y>=0:
                    res.append(mat[x][y])
                    x+=1
                    y-=1
        return res
s=[[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], [12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22], [23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33], [34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44], [45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55], [56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66], [67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77], [78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88]]
c=Solution()
print(c.findDiagonalOrder(s))