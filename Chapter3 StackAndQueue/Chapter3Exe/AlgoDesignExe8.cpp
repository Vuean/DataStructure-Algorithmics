#include <iostream>
using namespace std;

// 约定front指向队头元素的前一位置，rear指向队尾元素。
const int MAXSIZE = 100;
typedef int elemtype;
struct cycQueue{
    elemtype* data;
    int front, rear;
};

void InitQueue(cycQueue* Q){
    Q->data = new elemtype[MAXSIZE];
    Q->front = Q->rear = 0;
}

// 从队尾删除
void DeleteQueue(cycQueue* Q, elemtype& e){
    if(Q->front == Q->rear){
        cout << "队空" << endl;
        return;
    }
    e = Q->data[Q->rear];
    Q->rear = (Q->rear - 1 + MAXSIZE) % MAXSIZE;
}

// 从队头插入
void InputQueue(cycQueue* Q, elemtype e){
    if(Q->rear == (Q->front - 1 + MAXSIZE) % MAXSIZE){
        cout << "栈满" << endl;
    }
    Q->data[Q->front] = e;
    Q->front = (Q->front + 1) % MAXSIZE;
}