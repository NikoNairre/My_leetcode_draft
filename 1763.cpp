#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool is_perfect(string test){
    bool perfect=true;
    for(int i=0;i<test.size();i++){
        if(test[i]>=97){
            if(test.find(test[i]-32)>test.size()){
                perfect=false; break;
            }
        }else{
            if(test.find(test[i]+32)>test.size()){
                perfect=false; break;
            }
        }
    }
    return perfect;
}

vector<string> all_subs(string test){
    vector<string> sub_strings;
    for(int i=0;i<test.size();i++){
        for(int j=i;j<test.size();j++){
            sub_strings.emplace_back(test.substr(i,j-i+1));
        }
    }
    return sub_strings;
}

vector<string> all_perfects(string test){
    vector<string>subs=all_subs(test);
    vector<string>perfects;
    for(auto item:subs){
        if(is_perfect(item)==true){
            perfects.emplace_back(item);
        }
    }
    return perfects;
}
int main(){
    string a="aaabbbcccdedd";
    string b="aAaBb";
    cout<<is_perfect(a)<<endl;
    cout<<is_perfect(b)<<endl;
    vector<string> c=all_perfects(a);
    for(auto item:c){
        cout<<item<<" ";
    }
    return 0;
}