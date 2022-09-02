#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    unordered_map<char,vector<char>>graph;  //邻接表形式的图
    unordered_map<char,int>state;           //图中每个字符结点的状态，0表示未访问，1表示访问中，2表示访问完毕
    bool valid=true;                        //判断给出的字串集是否合法，以及作为dfs是否返回的标识
    stack<char>letter_pool;                 //存放结果的栈

    string alienOrder(vector<string>& words) {    //"主"函数
        for(auto word:words){
            for(int i=0;i<word.size();i++){
                if(!graph.count(word[i])){
                    graph[word[i]]=vector<char>();    //将字串集中出现的所有元素加入图中，作为连通图的结点
                    state[word[i]]=0;                 //将结点的状态设置为“未访问”，同时避免了dfs时找不到结点的情况（主要是另一种做法使用了集合的count方法）
                }
            }
        }
        for(int i=1;i<words.size() and valid;i++){
            addEdge(words[i-1],words[i]);          //addEdge为加边函数，通过对字串集中每两个相邻字符串的遍历，给图中结点添加邻边
        }
        for(auto point:graph){                     //对图进行深度优先搜索，dfs为深度优先搜索函数
            char c_letter=point.first;
            if(state[c_letter]==0){
                dfs(c_letter);
            }
        }
        if(!valid){                               //如果字串集本身就不合法，则输出空
            return "";
        }
        string res;                               //又dfs得到的栈还原出拓扑排序的结果（该题中，拓扑排序与dfs得到的字符序列相反，故使用栈）
        while(!letter_pool.empty()){              //该题的拓扑排序即为最终的答案
            res+=letter_pool.top();
            letter_pool.pop();
        }
        return res;
    }

    void addEdge(string pre,string cur){        //加边函数
        int l1=pre.size(); int l2=cur.size();
        int valid_length=min(l1,l2);            //字典序大小以两字符串的长度为其中一个依据，当a的长度大于b，且b为a的前缀，那么b的字典序就小于a
        int index=0;
        while(index<valid_length){              //对两字符串进行逐个字符检查
            if(pre[index]!=cur[index]){         //如果同一位置两个字符不等，那么认为前者的字典序小于后者，即在外星语字母表中，前者该字符排在后者该字符之前
                graph[pre[index]].emplace_back(cur[index]);  //字母大小关系抽象成单边的联系，假设小联系大，完成加边操作
                break;                          //该情况下，字符大小判断已经完成，无需继续比对
            }
            index++;
        }
        if(index==valid_length and l1>l2){      //已经找完了，当出现后字串b是前字串a的前缀，并且a的长度大于b，那么该字符串集是不合法的，可以直接输出结果""了
            valid=false;
        }
                                                //类似"ab","abc"这种情况，是合法的
    }

    void dfs(char x){             //深度优先搜索函数
        state[x]=1;               //将当前字符设置为正在访问
        for(auto v:graph[x]){     //寻找邻接结点
            if(state[v]==0){
                dfs(v);           //如果邻结点v没有被访问过，那么对v进行递归地深度优先搜索
                if(valid==false){ //不合法就返回退出
                    return;
                }
            }
            if(state[v]==1){      //如果该节点正在被访问，那此时不能搜索v，只能继续寻找其他的邻结点
                valid=false;
        //        return;       //这个return加上去，会减少消耗的内存，加和不加都可以通过该题
            }
        }
        state[x]=2;          //当前结点的所有邻结点都已被访问，则将该结点标记为访问结束
        letter_pool.emplace(x);//此时在结果栈中添加该字符
    }
};

int main(){

    return 0;
}