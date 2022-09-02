#include<iostream>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        array_len=k;
        for(int i=0;i<k;i++){
            array[i]=-1;
        }
        cur_elements=0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else{
            for(int i=array_len-2;i>=0;i--){
                array[i+1]=array[i];
            }
            array[0]=value;
            cur_elements++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            array[cur_elements-1]=-1;
            cur_elements--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }else{
            return array[cur_elements-1];
        }
    }
    
    int Rear() {
        if(array[0]!=-1){
            return array[0];
        }else{
            return -1;
        }
    }
    
    bool isEmpty() {
        if(cur_elements==0){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(cur_elements==array_len){
            return true;
        }else{
            return false;
        }
    }
private:
    int array[1001];
    int array_len;
    int cur_elements;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){

    return 0;
}