/*
���ַ�ǰһ����ջ��Ȼ��ջ��Ԫ�غ��ַ�����һ����бȽϡ�����
��һ��Ԫ�س�ջ�ͺ�һ�봮�еĵ�һ��Ԫ�رȽϣ�����ȣ����ٳ�
ջ��һ��Ԫ�����һ��Ԫ�رȽϡ�����ֱ��ջ�գ�����Ϊ���ģ�����
Ϊ�ǻ��ġ�
*/
#include <string>
#include "AlgoDesignStack.h"

typedef char DataType;

int IsHuiWen(char* t){
    SqStack s;
    int i = 0, len;
    char temp;
    InitStack(s);
    len = strlen(t);
    for(; i < len / 2; i++){
        Push(s, t[i]);
    }
    if(len % 2 != 0){
        i++;
    }
    while(!StackEmpty(s)){
        Pop(s, temp);
        if(temp == t[i]){
            i++;
        } else{
            return 0;
        }
    }
    return 1;
}