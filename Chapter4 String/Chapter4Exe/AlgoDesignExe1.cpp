// ͳ�������ַ����������ַ�����ĸ�ַ��ĸ�����
#include <cstdio>
#include <iostream>
using namespace std;
void count()
{
    int index, num[36];
    char ch;
    for(int i = 0; i < 36; i++){
        num[i] = 0;
    }
    while(ch = getchar() != '#'){
        if(ch >= '0' && ch <= '9'){
            index = ch - 48;
            num[index]++;
        }else if(ch >= 'A' && ch <= 'Z'){
            index = ch - 65 + 10;
            num[index]++;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << "����" << i << "�ĸ��� = " << num[i] << endl;
    }
    for(int i = 10; i < 36; i++){
        cout << "��ĸ" << i+55 << "�ĸ��� = " << num[i] << endl;
    }
}