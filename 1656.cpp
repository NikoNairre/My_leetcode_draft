#include<iostream>
#include<vector>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        values.resize(n+1);
        ptr=1;
    }
    
    vector<string> insert(int idKey, string value) {
        values[idKey]=value;
        vector<string>ans;        
        while(ptr<values.size() and !values[ptr].empty()){
            ans.emplace_back(values[ptr]);
            ptr++;
        }
        return ans;
    }
private:
    vector<string>values;
    int ptr;
    
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main(){

    return 0;
}