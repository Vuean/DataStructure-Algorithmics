// 字符串逆序存储的递归算

#include <iostream>
using namespace std;

void InvertStore(char A[]){
    char ch;
    static int i = 0;// 需要使用静态变量
    cin >> ch;
    if(ch != '.'){  // 规定'.'是字符串输入结束标志
        InvertStore(A);
        A[i++] = ch;
    }
    A[i] = '\0';    // 字符串结尾标记
}