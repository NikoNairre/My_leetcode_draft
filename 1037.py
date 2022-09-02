class Solution:
    def isBoomerang(self, points: list[list[int]]) -> bool:
        point1=points[0]
        point2=points[1]
        point3=points[2]
        if point1[0]==point2[0]:
            if point1[1]!=point2[1] and point3[0]!=point1[0]:
                return True
            else:
                return False
        k=(point1[1]-point2[1])/(point1[0]-point2[0])
        b=point1[1]-k*point1[0]
        x3=point3[0];y3=point3[1]
        y=k*x3+b
        if abs(y-y3)>0.01:
            return True
        else:
            return False
l=[[0,1],[1,0],[0,1]]
a=Solution()
print(a.isBoomerang(l))