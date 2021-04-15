#include <iostream>
using namespace std;

// Լ��frontָ���ͷԪ�ص�ǰһλ�ã�rearָ���βԪ�ء�
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

// �Ӷ�βɾ��
void DeleteQueue(cycQueue* Q, elemtype& e){
    if(Q->front == Q->rear){
        cout << "�ӿ�" << endl;
        return;
    }
    e = Q->data[Q->rear];
    Q->rear = (Q->rear - 1 + MAXSIZE) % MAXSIZE;
}

// �Ӷ�ͷ����
void InputQueue(cycQueue* Q, elemtype e){
    if(Q->rear == (Q->front - 1 + MAXSIZE) % MAXSIZE){
        cout << "ջ��" << endl;
    }
    Q->data[Q->front] = e;
    Q->front = (Q->front + 1) % MAXSIZE;
}