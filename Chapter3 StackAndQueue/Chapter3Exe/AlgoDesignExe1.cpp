#include <iostream>
using namespace std;

typedef int SElemType;

struct DblStack{
    int top[2], bot[2]; // ջ����ջ��ָ��
    SElemType* V;       // ջ����
    int m;              // ջ��������Ԫ�ظ���
};