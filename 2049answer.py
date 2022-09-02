class Solution:
    def __init__(self):
        self.left = [-1 for i in range(100001)]   # 左孩子标号 （不存在为 -1）
        self.right = [-1 for i in range(100001)]  # 右孩子标号 （不存在为 -1）
        self.size = [0 for i in range(100001)]    # 当前节点大小

    def dfs(self,x):
        self.size[x] = 1  # 第一次遍历到这个节点的时候，先给大小置为 1 （包括自己）
        if self.left[x] != -1:  # 如果左孩子存在，递归搜索左孩子
            self.dfs(self.left[x])
            self.size[x] += self.size[self.left[x]]  # 当前节点的大小要加上左孩子的大小
        if self.right[x] != -1: # 如果右孩子存在，递归搜索右孩子
            self.dfs(self.right[x])
            self.size[x] += self.size[self.right[x]] # 当前节点的大小要加上右孩子的大小


    def countHighestScoreNodes(self, parents: list[int]) -> int:
        n = len(parents)
        for i in range(1,n):
            if self.left[parents[i]] == -1:   # 如果左孩子不存在，将其置为左孩子
                self.left[parents[i]] = i
            else:                             # 否则置为右孩子
                self.right[parents[i]] = i
        self.dfs(0)  # 递归搜索，完成__init__函数里的列表
        max_time = 0   # 最大节点出现次数
        max_num = 0   # 最大节点数
        for i in range(n):  # 查询答案
            p1 = n - self.size[i] # 外部子树大小
            p2 = 1 # 左子树大小
            p3 = 1 # 右子树大小
            if i == 0:
                p1 = 1  # 0 节点无外部点
            if self.left[i] != -1:  # 如果左子树存在
                p2 = self.size[self.left[i]]
            if self.right[i] != -1:  # 如果右子树存在
                p3 = self.size[self.right[i]]
            if p1 * p2 * p3 > max_num:  # 如果当前节点的3个值乘起来大于最大值，则重新赋值最大值，将次数归一
                max_num = p1 * p2 * p3
                max_time = 1
            elif p1 * p2 * p3 == max_num:  # 如果再次出现最大值，次数加一
                max_time += 1
        return max_time  # 返回最大值出现的次数
