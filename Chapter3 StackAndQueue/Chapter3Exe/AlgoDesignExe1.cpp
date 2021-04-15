#include <iostream>
using namespace std;

typedef int SElemType;

/*
��Ŀ��������ջ���������ռ䣬����ջջ�������������ˣ�
��ʼʱ����ջ��ָ��Ϊ��-1����ջ��Ϊm����ջ��ָ������ʱΪջ����
��ջ������ӭ��������ջ��ָ��ָ��ջ��Ԫ�ء�
*/

struct DblStack{
    int top[2], bot[2]; // ջ����ջ��ָ��
    SElemType* V;       // ջ����
    int m;              // ջ��������Ԫ�ظ���

    int Init();         // ��ʼ��
    int push(DblStack* S, int i, int x);    // ��ջ
    int pop(DblStack* S, int i);            // ��ջ
    bool IsEmpty(); // �ж�ջ��
};

int DblStack::Init(){
    this->top[0] = -1;
    this->top[1] = m;
    return 1;   // ��ʼ���ɹ�
}

// i��ʾջ�ţ�0Ϊ��ջ��1Ϊ��ջ
int DblStack::push(DblStack* S, int i, int x){
    S = this;
    if(i < 0 || i > 1){
        return 0;   // ʧ��
    }
    switch(i){
    case 0:
        S->V[++S->top[0]] = x;
        break;
    case 1:
        S->V[--S->top[1]] = x;
        break;
    default:
        break;
    }
    return 1;
}

int DblStack::pop(DblStack* S, int i){
    if(i < 0 || i > 1){
        return -1;
    }
    switch(i){
    case 0:
        if(S->top[0] == -1){
            return -1;
        }else{
            return S->V[S->top[0]--];
        }
        break;
    case 1:
        if(S->top[1] == m){
            return -1;
        } else{
            return S->V[S->top[1]++];
        }
        break;
    default:
        break;
    }
}


bool DblStack::IsEmpty(){
    return (this->top[0] == 1 && this->top[1] == m);
}