// �ַ�������洢�ĵݹ���

#include <iostream>
using namespace std;

void InvertStore(char A[]){
    char ch;
    static int i = 0;// ��Ҫʹ�þ�̬����
    cin >> ch;
    if(ch != '.'){  // �涨'.'���ַ������������־
        InvertStore(A);
        A[i++] = ch;
    }
    A[i] = '\0';    // �ַ�����β���
}