/*
将字符前一半入栈，然后栈中元素和字符串后一半进行比较。即将
第一个元素出栈和后一半串中的第一个元素比较，若相等，则再出
栈下一个元素与后一个元素比较。。。直至栈空，返回为回文，否则
为非回文。
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