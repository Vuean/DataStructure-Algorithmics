// ���ַ���t�����ַ���s�ĵ�pos��λ��
#include <iostream>
using namespace std;

void insert(char* s, char* t, int pos){
    int i = 1, x = 0;
    char *p = s, *q = t;    // p��q���ֱ�Ϊ�ַ���s��t�Ĺ���ָ��
    if(pos < 1){
        cout << "pos����λ�÷Ƿ�" << endl;
        return;
    }
    // ����posλ��
    while(*p != '\0' && i < pos){
        p++;
        i++;
    }
    if(*p == '\0'){
        cout << "pos���������ַ���s�ĳ���" << endl;
        return;
    }else{
        // �����ַ�����β
        while(*p != '\0'){
            // �鵽βʱ��iΪ�ַ�'\0'���±꣬pҲָ��'\0'
            p++;
            i++;
        }
        while(*q != '\0'){
            // ����t�ĳ���x��ѭ������ʱ��qָ��'\0'
            q++;
            x++;
        }
        for(int j = i; j >= pos; j--){
            // ��s��pos����Ӵ����ƣ��ճ���t��λ�á�
            *(p+x) = *p;
            p--;
        }
        q--;    // ָ��q���˵���t�����һ���ַ�
        for(int j = 1; j <= x; j++){
            // ��t�����뵽s��posλ����
            *p-- = *q--;
        }
    }
}