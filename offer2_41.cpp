#include<iostream>
#include<queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size=size;
        this->sum_val=0.0;
    }
    
    double next(int val) {
        if(op_queue.size()==size){
            sum_val-=op_queue.front();
            op_queue.pop();
        }
        sum_val+=val;
        op_queue.emplace(val);
        return (double)sum_val/size;
    }
private:
    int size;
    double sum_val;
    queue<int>op_queue;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(){

    return 0;
}