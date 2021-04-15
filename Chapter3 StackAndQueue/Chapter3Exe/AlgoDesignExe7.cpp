#include <iostream>
using namespace std;

const int MAXQSIZE = 100;
typedef int QElemType;

struct SqQueue{
    QElemType *base;    // ��ʼ���Ķ�̬����洢�ռ�
    int front;  // ͷָ�룬�����в�Ϊ�գ�ָ�����ͷԪ��
    int rear;   // βָ�룬�����в�Ϊ�գ�ָ���βԪ�ص���һ��λ��
    int tag;
};

void Init(SqQueue &Q){
    Q.base = new QElemType[MAXQSIZE];
    Q.front = Q.rear = 0;
    Q.tag = 0;
}

// ���
void InQueue(SqQueue &Q, QElemType e){
    if((Q.tag == 1) && (Q.front == Q.rear)){
        cout << "����" << endl;
        return;
    }else{
        Q.rear = (Q.rear + 1) % MAXQSIZE;
        Q.base[Q.rear] = e;
        if(Q.tag == 0){
            Q.tag = 1;
        }
    }
}

// ����
void OutQueue(SqQueue &Q, QElemType& e){
    if(Q.tag == 0){
        cout << "�ӿ�" << endl;
    }
    else{
        e = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXQSIZE;
        if(Q.front == Q.rear){
            Q.tag = 0;
        }
    }
}

