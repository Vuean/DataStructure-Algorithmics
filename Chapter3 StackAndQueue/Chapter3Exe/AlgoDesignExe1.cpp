#include <iostream>
using namespace std;

typedef int SElemType;

/*
题目分析：两栈共享向量空间，将两栈栈底设在向量两端，
初始时，左栈顶指针为－-1，右栈顶为m。两栈顶指针相邻时为栈满。
两栈顶相向、迎面增长，栈顶指针指向栈顶元素。
*/

struct DblStack{
    int top[2], bot[2]; // 栈顶和栈底指针
    SElemType* V;       // 栈数组
    int m;              // 栈最大可容纳元素个数

    int Init();         // 初始化
    int push(DblStack* S, int i, int x);    // 入栈
    int pop(DblStack* S, int i);            // 出栈
    bool IsEmpty(); // 判断栈空
};

int DblStack::Init(){
    this->top[0] = -1;
    this->top[1] = m;
    return 1;   // 初始化成功
}

// i表示栈号，0为左栈，1为右栈
int DblStack::push(DblStack* S, int i, int x){
    S = this;
    if(i < 0 || i > 1){
        return 0;   // 失败
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