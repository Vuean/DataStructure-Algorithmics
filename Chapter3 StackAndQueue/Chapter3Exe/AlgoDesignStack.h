#define MAXSIZE 100
typedef char SElemType;
struct SqStack{
    SElemType *base;    // 栈底指针
    SElemType *top;     // 栈顶指针
    int stacksize;      // 栈可用最大容量
};

// 构造一个空栈
int InitStack(SqStack &S){
    S.base = new SElemType[MAXSIZE];
    if(!S.base) return -1; // 存储分配失败
    S.top = S.base; // 栈顶指针等于栈底指针
    S.stacksize = MAXSIZE;
    return 0;
}

// 判断顺序栈是否为空
bool StackEmpty(SqStack &S){
    if(S.top == S.base)
        return true;
    else
        return false;
}

// 求顺序栈的长度
int StackLength(const SqStack &S)
{
    return S.top - S.base;
}

// 清空顺序栈
int ClearStack(SqStack &S){
    if(S.base) S.top = S.base;
    return 0;
}

// 销毁顺序栈
int DestoryStack(SqStack &S){
    if(S.base){
        delete S.base;
        S.stacksize = 0;
        S.base = S.top = nullptr;
    }
    return 0;
}

// 顺序栈的入栈
int Push(SqStack &S, SElemType e){
    if(S.top - S.base == S.stacksize)   // 栈满
        return -1;
    *S.top = e;
    S.top++;
    // 等同于
    // *S.top++ = e;
    return 0;
}

int Pop(SqStack &S, SElemType &e)
{
    if(S.top  == S.base) return -1;
    S.top--;
    e = *S.top;
    // 等同于
    // e = *--S.top;
    return 0;
}