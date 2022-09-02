#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int>pool_pathLen;    //处理路径的栈，记录路径的长度
        int n=input.size();
        int pos=0;                 //当前处理进度的“指针”
        int result=0;
        while(pos<n){
            int depth=1;
            while(input[pos]=='\t'){   //获取当前文件（夹）的深度
                depth++;
                pos++;
                if(pos>=n){break;}
            }
            int cur_len=0;
            bool is_file=false;       //判断是不是文件，有"."的话就是
            while(input[pos]!='\n'){  //获取当前路径的长度
                if(input[pos]=='.'){
                    is_file=true;
                }
                cur_len++;
                pos++;
                if(pos>=n){break;}
            }
            pos++;   //跳过'\n',防止对之后的depth判断产生影响
            while(pool_pathLen.size()>=depth){      //当前路径深度没有比栈的深度小，需要先将栈的深度减小到（n-1）
                pool_pathLen.pop();
            }
            if(!pool_pathLen.empty()){         //向栈中存放路径长度
                pool_pathLen.emplace(cur_len+pool_pathLen.top()+1);//+1是因为路径中含有'/'
            }else{
                pool_pathLen.emplace(cur_len);//注意空栈的特殊情况
            }
            
            if(is_file){
                result=max(result,pool_pathLen.top());//获取最长路径
            }
        }
        return result;
    }
};

int main(){
    string s="dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    Solution a;
    cout<<a.lengthLongestPath(s)<<endl;
    return 0;
}