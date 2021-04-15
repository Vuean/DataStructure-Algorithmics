#include <iostream>
using namespace std;

const int MAXQSIZE = 100;
typedef int QElemType;

struct SqQueue{
    QElemType *base;    // 初始化的动态分配存储空间
    int front;  // 头指针，若队列不为空，指向队列头元素
    int rear;   // 尾指针，若队列不为空，指向队尾元素的下一个位置
    int tag;
};

void Init(SqQueue &Q){
    Q.base = new QElemType[MAXQSIZE];
    Q.front = Q.rear = 0;
    Q.tag = 0;
}

// 入队
void InQueue(SqQueue &Q, QElemType e){
    if((Q.tag == 1) && (Q.front == Q.rear)){
        cout << "队满" << endl;
        return;
    }else{
        Q.rear = (Q.rear + 1) % MAXQSIZE;
        Q.base[Q.rear] = e;
        if(Q.tag == 0){
            Q.tag = 1;
        }
    }
}

// 出队
void OutQueue(SqQueue &Q, QElemType& e){
    if(Q.tag == 0){
        cout << "队空" << endl;
    }
    else{
        e = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXQSIZE;
        if(Q.front == Q.rear){
            Q.tag = 0;
        }
    }
}

