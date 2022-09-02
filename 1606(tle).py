k=int(input())
arrival=[int(i) for i in input().split()]
load=[int(i) for i in input().split()]
assert len(arrival)==len(load)

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        if k==1:
            return [0]
        servers=[[0]*2+[True] for i in range(k)]
        max_mission=0

        for order,time in enumerate(arrival):
            for server in servers:
                max_mission=max(max_mission,server[0])
                if server[1]<=time:
                    server[1]=0
                    server[2]=True
            if servers[order%k][2]==True:
                servers[order%k][0]+=1
                max_mission=max(max_mission,servers[order%k][1])
                servers[order%k][1]=time+load[order]
                servers[order%k][2]=False
            else:
                another_pos=order+1
                while another_pos<order+k:
                    if servers[another_pos%k][2]==True:
                        servers[another_pos%k][0]+=1
                        max_mission=max(max_mission,servers[another_pos%k][0])
                        servers[another_pos%k][1]=time+load[order]
                        servers[another_pos%k][2]=False
                        break
                    another_pos+=1

        res=[]
        for i in range(len(servers)):
            if servers[i][0]==max_mission:
                res.append(i)
        return max_mission
ans=Solution()
print(ans.busiestServers(k,arrival,load))
