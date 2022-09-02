#include<iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {   //由题意，可知二进制n不含前导0
        while(!(n&1)){   //去除尾部的0，注意运算符优先级，"!"高于&
            n=n>>1;
        }
        int dis=0;
        int max_dis=0;
        while(n>0){
            if((n&1)==1 and ((n>>1)&1)==1){   //两个紧挨着的1的情况，注意运算优先级
                max_dis=max(dis,max_dis);   //记录上一对1的距离（如果上一对1存在）
                dis=1;                      //两个1紧挨时，距离为1
                max_dis=max(dis,max_dis);   //比较当前距离与最长距离
                n=n>>2;                     //由于一次性判断了2位，因此该情况下n需要右移2位
            }else{                      //普通情况
                if(n&1){                //当前位为1
                    max_dis=max(dis,max_dis);//1要重新配对了，在重新配对前先比较上一对1的距离
                    dis=1;              //新一对的1初始距离为1
                }else{
                    dis++;             //当前位为0，因为不含前导0，只需将距离递增即可
                }
                n=n>>1;               //普通情况下每次判断了1位，因此n每次右移1位
            } 
        }
        return max_dis;
    }
};

int main(){
    Solution a;
    cout<<a.binaryGap(13)<<endl;
    return 0;
}