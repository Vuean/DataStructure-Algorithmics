#define MAXSIZE 100
typedef char SElemType;
struct SqStack{
    SElemType *base;    // ջ��ָ��
    SElemType *top;     // ջ��ָ��
    int stacksize;      // ջ�����������
};

// ����һ����ջ
int InitStack(SqStack &S){
    S.base = new SElemType[MAXSIZE];
    if(!S.base) return -1; // �洢����ʧ��
    S.top = S.base; // ջ��ָ�����ջ��ָ��
    S.stacksize = MAXSIZE;
    return 0;
}

// �ж�˳��ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack &S){
    if(S.top == S.base)
        return true;
    else
        return false;
}

// ��˳��ջ�ĳ���
int StackLength(const SqStack &S)
{
    return S.top - S.base;
}

// ���˳��ջ
int ClearStack(SqStack &S){
    if(S.base) S.top = S.base;
    return 0;
}

// ����˳��ջ
int DestoryStack(SqStack &S){
    if(S.base){
        delete S.base;
        S.stacksize = 0;
        S.base = S.top = nullptr;
    }
    return 0;
}

// ˳��ջ����ջ
int Push(SqStack &S, SElemType e){
    if(S.top - S.base == S.stacksize)   // ջ��
        return -1;
    *S.top = e;
    S.top++;
    // ��ͬ��
    // *S.top++ = e;
    return 0;
}

int Pop(SqStack &S, SElemType &e)
{
    if(S.top  == S.base) return -1;
    S.top--;
    e = *S.top;
    // ��ͬ��
    // e = *--S.top;
    return 0;
}