class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        dp_array=[0 for i in range(10001)]
        k=min(coins)
        if k>10000:
            k=10000
        for i in range(len(coins)):
            if coins[i]<=10000:
                dp_array[coins[i]]=1
        for i in range(1,k,1):
            if k==1:
                pass
            else:
                dp_array[i]=-1
        for i in range(k+1,amount+1,1):
            possible_value=[]
            for j in range(len(coins)):
                minus_degree=i-coins[j]
                if minus_degree<0:
                    continue
                temp_value=dp_array[minus_degree]+1
                if temp_value>0:
                    possible_value.append(temp_value)
            if len(possible_value)==0:
                dp_array[i]=-1
            else:
                dp_array[i]=min(possible_value)
        
        return dp_array[amount]
a=[0 for i in range(5)]
a[2]=4
print(a)