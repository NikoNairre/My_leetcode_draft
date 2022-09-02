#include<iostream>
#include<vector>
using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        dcyl_queue=vector<int>(k+1);          //数组长度需要定为k+1
        capacity=k+1;
        front=rear=0;
    }
    
    bool insertFront(int value) {
        if(isFull()){return false;}
        
        front=(front+1)%capacity;          //获取循环队列中的后一位置
        dcyl_queue[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){return false;}
        dcyl_queue[rear]=value;
        rear=(rear-1+capacity)%capacity;   //获取循环队列中的前一位置
        
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){return false;}
        front=(front-1+capacity)%capacity;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){return false;}
        rear=(rear+1)%capacity;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){return -1;}
        return dcyl_queue[front];
    }
    
    int getRear() {
        if(isEmpty()){return -1;}
        return dcyl_queue[(rear+1)%capacity];
    }
    
    bool isEmpty() {
        return front==rear;
    }
    
    bool isFull() {
        return (front+1)%capacity==rear;
    }
private:
    vector<int>dcyl_queue;
    int capacity;
    int front,rear;
};

int main(){

    return 0;
}