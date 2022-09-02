#include<iostream>
using namespace std;

struct DLinkListNode {            //表示链表中的一个结点,用结构体定义 
    int val;                           
    DLinkListNode *prev, *next;       //指针指向前一个结点和后一个结点
    DLinkListNode(int _val): val(_val), prev(nullptr), next(nullptr) {     //初始化结点

    }
};

class MyCircularDeque {          
private:
    DLinkListNode *head, *tail;
    int capacity; 
    int size;

public:
    MyCircularDeque(int k): capacity(k), size(0), head(nullptr), tail(nullptr) {  //初始化私有成员的值
        
    }

    bool insertFront(int value) {
        if (size == capacity) {
            return false;
        }
        DLinkListNode *node = new DLinkListNode(value);
        if (size == 0) {
            head = tail = node;      //插入第一个结点，此时头就是尾
        } else {
            node->next = head;        //在head前面插入结点
            head->prev = node;          
            head = node;
        }
        size++;                   
        return true;
    }

    bool insertLast(int value) {
        if (size == capacity) {
            return false;
        }
        DLinkListNode *node = new DLinkListNode(value);
        if (size == 0) {
            head = tail = node;    
        } else {
            tail->next = node;    //在rear后面插入结点
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        DLinkListNode *node = head;
        head = head->next;        //移除头结点，并使下一个结点成为头结点
        if (head) {
            head->prev = nullptr;
        }
        delete node;         //删除59行新建的结点node
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        DLinkListNode *node = tail;
        tail = tail->prev;      //移除尾结点，并使前一个结点成为尾结点
        if (tail) {
            tail->next = nullptr;
        }
        delete node;
        size--;
        return true;
    }

    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->val;
    }

    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main(){

    return 0;
}