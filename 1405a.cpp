#include<iostream>
#include<sstream>
#include<queue>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        if(a==0 and b==0 and c==0){return "";}
        priority_queue<pair<int,char>>q;
        q.push(make_pair(a,'a'));
        q.push(make_pair(b,'b'));
        q.push(make_pair(c,'c'));
        stringstream ss;
        while(true){
            pair<int,char> biggest=q.top();
            q.pop();
            if(biggest.first==0){break;}
            string s=ss.str();
            
            if(ss.str().size()>=2 and s[s.size()-1]==biggest.second and s[s.size()-2]==biggest.second ){
                pair<int,char> middle=q.top();
                q.pop();
                if(middle.first==0){break;}
                ss<<middle.second;
                middle.first--;
                q.push(middle);
                q.push(biggest);
            }
            else{
                ss<<biggest.second;
                biggest.first--;
                q.push(biggest);
            }

        }
        return ss.str();
    }
};
int main(){
    Solution a;
    cout<<a.longestDiverseString(1,2,3);
    return 0;
}