#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int>squares;
        int max_length=0;
        for(auto item:rectangles){
            int length=min(item[0],item[1]);
            squares.push_back(length);
            if(max_length<length){
                max_length=length;
            }
        }
        int count=0;
        for(auto i :squares){
            if(i==max_length){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution a;
    vector<vector<int>>b={{5,8},{3,9},{5,12},{16,5}};
    cout<<a.countGoodRectangles(b);
    return 0;
}