#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int gcd(int x,int y){
        int temp;
        if(x<y){
            temp=x;
            x=y;
            y=temp;
        }
        while(y>0){
            temp=x%y;
            x=y;
            y=temp;
        }
        return x;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int>now={2,3,5,6,7,10,11,13,14,15,17,19,21,22,23,26,29,30};//只有这十八个数是我们考虑的
        vector<int>cnt(31,0);
        int N=1<<18;
        int shu=0;//统计1的个数
        for(auto i:nums)
        {
            cnt[i]++;//统计每个数出现的次数
            if(i==1)
            {
                shu++;//1的个数
            }
        }
        int mod=(int)1e9+7;
        
        long long ans=0;
        for(int i=1;i<N;i++)//枚举每一种状态
        {
            if(__builtin_popcount(i)==1)//二进制状态下，只有1个1，那肯定符合。
            {
                for(int j=0;j<18;j++)//找找这1个1在哪个位置
                {
                    if(((1<<j)&i))
                    {
                        ans+=cnt[now[j]];
                    }
                }
            }
            else{//此时有多个1
                long long flag=-1;//flag在第一次进入时，成为now[j]，之后就乘以now[j];
                long long k=1;//统计这种状态能形成的组合个数，因为乘法，所以初始化为1
                int ok=1;//是否合法的标记
                for(int j=17;j>=0;j--)
                {
                    if(((1<<j)&i))
                    {
                        if(flag==-1)
                        {
                            flag=now[j];
                            k*=cnt[now[j]];
                        }
                        else{
                            if(gcd(flag,now[j])!=1)//flag如果和now[j]的最大公因数不是1，说明他们的质因数有重复的，不合法，退出。
                            {
                                ok=0;
                                break;
                            }
                            flag*=now[j];
                            k*=cnt[now[j]];
                            k%=mod;
                            
                        }
                    }
                }
                if(ok)
                {
                    ans=(ans+k)%mod;
                }
                
            }
            
        }
        
        for(int i=0;i<shu;i++)
        {
            ans=ans*2%mod;//对于每一个1，我们可以选择或者不选择，所以每次乘2.
        }
        return ans;
    }
};
int main(){
    Solution a;
    vector<int>b={1,2,3,4};
    cout<<a.numberOfGoodSubsets(b)<<endl;
    cout<<a.gcd(20,8)<<endl;
    return 0;
}